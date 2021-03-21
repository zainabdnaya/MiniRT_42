/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:32:36 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"


t_objects *add_sphere_data(t_minirt *rt,t_vector center, double radius, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->center = center;
    obj->radius = radius/2;
    obj->color  = color;
    obj->wich_objects = 1;
    obj->next = NULL;
    obj->objects_index = rt->index1;
    rt->index1++;
    return (obj);
} 

t_objects *add_plan_data(t_minirt *rt,t_vector point,t_vector norm, t_color color)
{
    t_objects *obj;
    
    obj = malloc(sizeof(t_objects));

    obj->point = point;
    obj->normal = vectorNorme(norm);
    obj->color  = color;
    obj->wich_objects = 2;
    obj->next = NULL;
        obj->objects_index = rt->index1;
    rt->index1++;
    return (obj);  
}

t_objects *add_triangle_data(t_minirt *rt,t_vector point_a, t_vector point_b, t_vector point_c, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->point_a = point_a;
    obj->point_b = point_b;
    obj->point_c = point_c;
    obj->color = color;
    obj->wich_objects = 3;
    obj->next = NULL;
        obj->objects_index = rt->index1;
    rt->index1++;
    return (obj);
}

t_objects *add_square_data(t_minirt *rt,t_vector center, t_vector normal,double side_size, t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->sq_center = center;
    obj->normal = vectorNorme(normal);
    obj->side_size = side_size;
    obj->color = color;
    obj->wich_objects = 4;
    obj->next = NULL;
        obj->objects_index = rt->index1;
    rt->index1++;
    return (obj);
}

t_objects *add_cylindre_data(t_minirt *rt,t_vector center, t_vector normal,double diameter,double height,t_color color)
{
    t_objects *obj;

    obj = malloc(sizeof(t_objects));

    obj->cy_center = center;
    obj->cy_normal = vectorNorme(normal);
    obj->diameter = diameter / 2;
    obj->height = height;
    obj->color = color;
    obj->wich_objects = 5;
    obj->next = NULL;
        obj->objects_index = rt->index1;
    rt->index1++;
    return (obj);
}

