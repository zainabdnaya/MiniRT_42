/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:06:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

t_square *square_one(t_minirt *rt,t_square *square)
{
    if (!(square = malloc(sizeof(t_square))))
    {
        obj_error(23);
        exit(1);
    }
    square->center = vectorSplit(rt->pars.splitrest[1]);
    square->normal = vectorSplit(rt->pars.splitrest[2]);
    if ((square->normal.x > 1 || square->normal.x < -1) || (square->normal.y > 1 || square->normal.y < -1) || (square->normal.z > 1 || square->normal.z < -1))
    {
        obj_error(24);
        exit(1);
    }
    square->side_size = convert_to_double(rt->pars.splitrest[3]);
    if (square->side_size < 0)
    {
        obj_error(30);
        exit(1);
    }
    square->color = colorSplit(rt->pars.splitrest[4]);
    return(square);
}

void square_parsing(t_minirt *rt) 
{
    t_square   *square;

    square = NULL;
    if (ft_count(rt->pars.splitrest) == 5)
             square = square_one(rt,square);
    else if (ft_count(rt->pars.splitrest) == 7)
     {
         square = square_one(rt, square);
         square->translation = vectorSplit(rt->pars.splitrest[5]);
         square->rotation = vectorSplit(rt->pars.splitrest[6]);
         square->center = vectoradd(square->center,square->translation);
         square->normal = rotation(square->normal,square->rotation); 
     }
    add_objects(&rt->list_obj, add_square_data(rt,square->center, square->normal, square->side_size, square->color));
    free(square);
}

double  square_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;

    scal.one = vectordot(rt->list_obj->normal,ray_direction);
    if(scal.one != 0)
    {
        scal.up = vectorsub(rt->list_obj->sq_center,origin);
        rt->solution = (1/scal.one)*vectordot(scal.up,rt->list_obj->normal);
    }
    if(rt->solution > 0)
    {
        scal.produit = vectorscale(ray_direction, rt->solution);
        scal.point_pos = vectoradd(origin,scal.produit);
        scal.q_ed =  vectorsub(scal.point_pos,rt->list_obj->sq_center);
        scal.edge = rt->list_obj->side_size/ 2;
        if (fabs(scal.q_ed.x) > scal.edge || fabs(scal.q_ed.y) > scal.edge || fabs(scal.q_ed.z) > scal.edge)
            return (0);
        return (rt->solution);
    }
    return(0);
}

void calcul_square(t_minirt *rt )
{
    t_use scal;

    scal.one_scal = vectorscale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectoradd(rt->list_camera->look_from, scal.one_scal);
    scal.denominator = vectordot(rt->list_obj->normal,rt->ray_direction);
        if(scal.denominator > 0)
        rt->list_obj->normal = vectorscale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
}