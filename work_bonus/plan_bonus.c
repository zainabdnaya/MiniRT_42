/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:59:41 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

t_plan      *paln_one(t_minirt *rt, t_plan *plan)
{
     if (!(plan = malloc(sizeof(t_plan))))
    {
        obj_error(23);
        exit(1);
    }
    plan->point = vectorSplit(rt->pars.splitrest[1]);
    plan->norm = vectorSplit(rt->pars.splitrest[2]);
    if((plan->norm.x > 1 ||  plan->norm.x < -1) || (plan->norm.y > 1 || plan->norm.y < -1) || (plan->norm.z > 1 || plan->norm.z < -1))
    {
        obj_error(24);
        exit(1);
    } 
    plan->color = colorSplit( rt->pars.splitrest[3]);
    return(plan);
}

void plan_parsing(t_minirt *rt)
{
    t_plan *plan;
    
    plan = NULL;
    if (ft_count(rt->pars.splitrest) ==  4)
            plan = paln_one(rt,plan);
    else if (ft_count(rt->pars.splitrest) ==  6)
    {
            plan = paln_one(rt,plan);
    plan->point = translation(rt->pars.splitrest[4],plan->point);
    plan->norm = rotation_1(rt->pars.splitrest[5],plan->norm);
    }
    else
    {
        free(plan);
        obj_error(25);
        exit(1);
    }
    add_objects(&rt->list_obj, add_plan_data(rt,plan->point, plan->norm, plan->color));
    free(plan);
}


double      plan_equation(t_minirt *rt,t_vector ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.denominator = vectordot(rt->list_obj->normal,ray_direction);
     if ( scal.denominator != 0.0)
    {
        scal.one_scal = vectorsub(rt->list_obj->point,origin);
        rt->solution = (vectordot(scal.one_scal,rt->list_obj->normal)) / scal.denominator;
        if ( rt->solution > 0)
         {  
              if(scal.denominator > 0)
            rt->list_obj->normal = vectorscale(rt->list_obj->normal,(-1));    
             return (rt->solution);
         }  
    }
    return (0);
}


void    calcul_plan(t_minirt *rt)
{

    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
    rt->list_obj->position.x = rt->list_camera->look_from.x + rt->list_obj->solution * rt->ray_direction.x;
    rt->list_obj->position.y = rt->list_camera->look_from.y + rt->list_obj->solution * rt->ray_direction.y;
    rt->list_obj->position.z = rt->list_camera->look_from.z + rt->list_obj->solution * rt->ray_direction.z;
}