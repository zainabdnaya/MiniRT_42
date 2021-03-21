/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:07:48 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

t_triangle *triangle_one(t_minirt *rt,t_triangle *triangle)
{
    if (!(triangle = malloc(sizeof(t_triangle))))
    {
        obj_error(23);
        exit(1);
    }
    triangle->point_a = vectorSplit(rt->pars.splitrest[1]);
    triangle->point_b = vectorSplit(rt->pars.splitrest[2]);
    triangle->point_c = vectorSplit(rt->pars.splitrest[3]);
    triangle->color = colorSplit(rt->pars.splitrest[4]);
    return(triangle);
}

void triangle_parsing(t_minirt *rt)
{
    t_triangle *triangle;

   triangle = NULL;
    if (ft_count(rt->pars.splitrest) == 4)
        triangle = triangle_one(rt,triangle);
    else if (ft_count(rt->pars.splitrest) == 5)
    {
        triangle = triangle_one(rt, triangle);
        triangle->translation = vectorSplit(rt->pars.splitrest[5]);
        triangle->point_a = vectoradd(triangle->point_a, triangle->translation);
        triangle->point_b = vectoradd(triangle->point_b, triangle->translation);
        triangle->point_c = vectoradd(triangle->point_c, triangle->translation);
    }
    else
    {
        free(triangle);
        obj_error(26);
        exit(1);
    }
    add_objects(&rt->list_obj, add_triangle_data(rt,triangle->point_a, triangle->point_b, triangle->point_c, triangle->color));
    free(triangle);
}


double    triangle_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.edge1 = vectorsub(rt->list_obj->point_b,rt->list_obj->point_a);
    scal.edge2 = vectorsub(rt->list_obj->point_c,rt->list_obj->point_a);
    scal.vect = vectorCross(ray_direction,scal.edge2);
    scal.determinant = vectordot(scal.vect,scal.edge1);
    if (fabs(scal.determinant) < __DBL_EPSILON__ )
        return(0);
    scal.diffrence= vectorsub(origin,rt->list_obj->point_a);
    scal.inverse_determinant = 1.0/scal.determinant;
    scal.u = (scal.inverse_determinant)* (vectordot(scal.diffrence,scal.vect));
    if(scal.u < 0.0 || scal.u > 1.0 )
        return(0);
    scal.vect1 = vectorCross(scal.diffrence,scal.edge1);
    scal.v = (vectordot(scal.vect1,ray_direction))*(scal.inverse_determinant);
    if(scal.v < 0 || scal.v + scal.u > 1.0)
            return(0);
    rt->solution = (vectordot(scal.vect1,scal.edge2)) * (scal.inverse_determinant);
            return(rt->solution);
}   

void    calcul_triangle(t_minirt *rt)
{
    t_use scal;

        scal.edge1 = vectorsub(rt->list_obj->point_b,rt->list_obj->point_a);
    scal.edge2 = vectorsub(rt->list_obj->point_c,rt->list_obj->point_a);
    scal.one_scal = vectorscale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectoradd(rt->list_camera->look_from, scal.one_scal);
        rt->list_obj->normal = vectorCross(scal.edge1,scal.edge2);
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
        if(vectordot( rt->list_obj->normal,rt->ray_direction) > __DBL_EPSILON__)
            rt->list_obj->normal = vectorscale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);

    //rt->l_norm = vectorsub(rt->light->position, rt->list_obj->position);
}