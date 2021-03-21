/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:23:59 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"


t_cylindre  *cylindre_one(t_minirt *rt,t_cylindre *cylindre)
{
    if (!(cylindre = malloc(sizeof(t_cylindre))))
    {
        obj_error(23);
        exit(1);
    }
    cylindre->center = vectorSplit(rt->pars.splitrest[1]);
    cylindre->cy_normal = vectorSplit(rt->pars.splitrest[2]);
    if ((cylindre->cy_normal.x > 1 || cylindre->cy_normal.x < -1) || (cylindre->cy_normal.y > 1 || cylindre->cy_normal.y < -1) || (cylindre->cy_normal.z > 1 || cylindre->cy_normal.z < -1))
    {
        obj_error(24);
        exit(1);
    }
    cylindre->color = colorSplit(rt->pars.splitrest[3]);
    cylindre->diameter = convert_to_double(rt->pars.splitrest[4]);
    cylindre->height = convert_to_double(rt->pars.splitrest[5]);
    if (cylindre->diameter < 0 || cylindre->height < 0)
    {
        obj_error(29);
        exit(1);
    }
    return(cylindre);
}

void  cylindre_parsing(t_minirt *rt)
{
    t_cylindre *cylindre;

    cylindre = NULL;
    if (ft_count(rt->pars.splitrest) == 6)
        cylindre = cylindre_one(rt,cylindre);
    else if (ft_count(rt->pars.splitrest) == 8)
       {
            cylindre = cylindre_one(rt, cylindre);
            cylindre->translation = vectorSplit(rt->pars.splitrest[6]);
            cylindre->rotation = vectorSplit(rt->pars.splitrest[7]);
            cylindre->center = vectoradd(cylindre->center, cylindre->translation);
            cylindre->cy_normal = rotation(cylindre->cy_normal, cylindre->rotation);
       }
    else
       {
            free(cylindre);
            obj_error(28);
            exit(1);
       }
    add_objects(&rt->list_obj,add_cylindre_data(rt,cylindre->center,cylindre->cy_normal,cylindre->diameter, cylindre->height,cylindre->color));
    free(cylindre);
}


double      cylindre_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.a = vectordot(ray_direction,ray_direction) - pow(vectordot(ray_direction,rt->list_obj->cy_normal),2);
    scal.x_vect = vectorsub(origin,rt->list_obj->cy_center);
    scal.b = 2 * (vectordot(ray_direction,scal.x_vect)-(vectordot(ray_direction,rt->list_obj->cy_normal)* vectordot(scal.x_vect,rt->list_obj->cy_normal)));
    scal.c = vectordot(scal.x_vect,scal.x_vect) - (pow(vectordot(scal.x_vect,rt->list_obj->cy_normal),2)) - (pow(rt->list_obj->diameter,2));
    scal.discriminant = scal.b * scal.b - 4 * scal.a * scal.c;
    if (scal.discriminant < 0)
             return (0);
    scal.t3 = (-scal.b + sqrt(scal.discriminant)) / (2 * scal.a);
    scal.t4 = (-scal.b - sqrt(scal.discriminant)) / (2 * scal.a);
    scal.m = vectordot(ray_direction,rt->list_obj->cy_normal) * scal.t3 + vectordot(scal.x_vect,rt->list_obj->cy_normal);
    scal.m1 = vectordot(ray_direction,rt->list_obj->cy_normal) * scal.t4 + vectordot(scal.x_vect,rt->list_obj->cy_normal);
    if (scal.m1 >= 0 && scal.m1 <= rt->list_obj->height)
    {
        rt->solution = scal.t4;
        rt->m = scal.m1;
    } 
    else if (scal.m >= 0 && scal.m <= rt->list_obj->height)
    {
         rt->solution = scal.t3;
         rt->m = scal.m;
    }
    else
        rt->solution = 0;
    return(rt->solution);
}

void    calcul_cylindre(t_minirt *rt)
{
    t_use scal;
    
    scal.one_scal = vectorscale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectoradd(rt->list_camera->look_from, scal.one_scal);
    scal.vect = vectorsub(rt->list_obj->position,rt->list_obj->cy_center);
    scal.vect1 = vectorscale(rt->list_obj->cy_normal,rt->m);
    scal.vect2 =  vectorsub(scal.vect,scal.vect1);
    rt->list_obj->normal = vectorNorme(scal.vect2);
    if(vectordot(rt->ray_direction,rt->list_obj->normal) > 0.0)
                rt->list_obj->normal = vectorscale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
}





