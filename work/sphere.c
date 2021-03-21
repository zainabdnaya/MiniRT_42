/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:17:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_sphere *sphere_one(t_minirt *rt,t_sphere *sphere)
{
     if(!(sphere =  malloc(sizeof(t_sphere))))
       {
           obj_error(23);
           exit(1);
       }
    sphere->center = vectorSplit(rt->pars.splitrest[1]);
    sphere->radius = convert_to_double(rt->pars.splitrest[2]);
    if ( sphere->radius < 0 )
        {
            obj_error(22);
            exit(1);
        }
    sphere->color  = colorSplit(rt->pars.splitrest[3]);
    return(sphere);
}

void        sphere_parsing(t_minirt *rt)
{
    t_sphere    *sphere;

    sphere = NULL;
    if (ft_count(rt->pars.splitrest) == 4)
        sphere = sphere_one(rt,sphere);
    else if (ft_count(rt->pars.splitrest) == 5)
    {
           sphere = sphere_one(rt,sphere);
          sphere->translation = vectorSplit(rt->pars.splitrest[4]);
          sphere->center = vectoradd(sphere->center,sphere->translation);
    }
    else 
    {
            free(sphere);
            obj_error(21);
            exit(1);
    }
    add_objects(&rt->list_obj, add_sphere_data(rt,sphere->center, sphere->radius, sphere->color));
    free(sphere);
}

double sphere_equation(t_minirt *rt,t_vector ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.scal1 = vectordot(ray_direction,ray_direction); // A
    scal.dist = vectorsub(origin, rt->list_obj->center);
    scal.scal2 = 2 * vectordot(ray_direction, scal.dist); // B
    scal.rst = vectordot(scal.dist, scal.dist) - (pow(rt->list_obj->radius, 2)); // C 
    scal.delta = (pow(scal.scal2, 2)) - (4 * scal.scal1 * scal.rst);
    if (scal.delta < 0)
        return (0);
    else
    {
        scal.t1 = (-scal.scal2 + sqrt(scal.delta)) / 2 * scal.scal1;
        scal.t2 = (-scal.scal2 - sqrt(scal.delta)) / 2 * scal.scal1;
        if (scal.t1 < 0)
            return (0);
        if (scal.t1 < scal.t2)
            rt->solution = scal.t1;
        else
            rt->solution = scal.t2;
        return (rt->solution);
    }
}



void      calcul_sphere(t_minirt *rt)
{
    t_use scal;
    
    scal.one_scal = vectorscale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectoradd(rt->list_camera->look_from, scal.one_scal);
    t_vector discrt = vectorsub(rt->list_obj->position, rt->list_obj->center);
    rt->list_obj->normal = vectorNorme((discrt));
    
}