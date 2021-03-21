/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:17:13 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:56:08 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

t_vector        translation(char *str_to_convert,t_vector add_in)
{
    t_vector result;
    t_vector add_to;
    
    add_to = vectorSplit(str_to_convert);
    result = vectoradd(add_in,add_to);
    return(result);
}


void        camera_translation(t_minirt *rt,int keycode)
{
       if(keycode == 0)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x - 0.2; 
        if(keycode == 2)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x + 0.2; 
        if(keycode == 13)
            rt->list_camera->look_from.y = rt->list_camera->look_from.y + 0.2;
        if(keycode == 1)
            rt->list_camera->look_from.y = rt->list_camera->look_from.y - 0.2;
        if(keycode == 69)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z + 0.2;
        if(keycode == 78)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z - 0.2;
        
}


void        light_translation(t_minirt *rt,int keycode)
{
         if(keycode == 0)
            rt->clone.lights->position.x = rt->clone.lights->position.x - 5; 
        if(keycode == 2)
            rt->clone.lights->position.x = rt->clone.lights->position.x + 5; 
        if(keycode == 13)
            rt->clone.lights->position.y = rt->clone.lights->position.y + 5;
        if(keycode == 1)
            rt->clone.lights->position.y = rt->clone.lights->position.y - 5;
        if(keycode == 69)
            rt->clone.lights->position.z = rt->clone.lights->position.z + 5;
        if(keycode == 78)
            rt->clone.lights->position.z = rt->clone.lights->position.z - 5;
}


void       sphere_translation(t_minirt *rt,int keycode)
{
    if (keycode == 0 )
        rt->clone.objects->center.x = rt->clone.objects->center.x - 5;
    if (keycode == 2 )
        rt->clone.objects->center.x = rt->clone.objects->center.x + 5;
    if (keycode == 13 )
        rt->clone.objects->center.y = rt->clone.objects->center.y + 5;
    if (keycode == 1 )
        rt->clone.objects->center.y = rt->clone.objects->center.y - 5;
    if (keycode == 69 )
        rt->clone.objects->center.z = rt->clone.objects->center.z + 5;
    if (keycode == 78 )
        rt->clone.objects->center.z = rt->clone.objects->center.z - 5;
}


void       cylindre_trans(t_minirt *rt,int keycode)
{
        if(keycode == 0 )
            rt->clone.objects->cy_center.x = rt->clone.objects->cy_center.x - 5;
        if (keycode == 2 )
            rt->clone.objects->cy_center.x = rt->clone.objects->cy_center.x + 5;
        if (keycode == 13 )
            rt->clone.objects->cy_center.y = rt->clone.objects->cy_center.y + 5;
        if (keycode == 1 )
            rt->clone.objects->cy_center.y = rt->clone.objects->cy_center.y - 5;
        if (keycode == 69)
            rt->clone.objects->cy_center.z = rt->clone.objects->cy_center.z + 5;
        if (keycode == 78)
            rt->clone.objects->cy_center.z = rt->clone.objects->cy_center.z - 5;
}

void plan_trans(t_minirt *rt, int keycode)
{
    if (keycode == 0)
        rt->clone.objects->point.x = rt->clone.objects->point.x - 5;
    if (keycode == 2)
        rt->clone.objects->point.x = rt->clone.objects->point.x + 5;
    if (keycode == 13)
        rt->clone.objects->point.y = rt->clone.objects->point.y + 5;
    if (keycode == 1)
        rt->clone.objects->point.y = rt->clone.objects->point.y - 5;
    if (keycode == 69)
        rt->clone.objects->point.z = rt->clone.objects->point.z + 5;
    if (keycode == 78)
        rt->clone.objects->point.z = rt->clone.objects->point.z - 5;
}

void triangle_trans1(t_minirt *rt,int keycode)
{
     if (keycode == 1)
{
    rt->clone.objects->point_a.y = rt->clone.objects->point_a.y - 5;
    rt->clone.objects->point_b.y = rt->clone.objects->point_b.y - 5;
    rt->clone.objects->point_c.y = rt->clone.objects->point_c.y - 5;
}            if (keycode == 69)
{
    rt->clone.objects->point_a.z = rt->clone.objects->point_a.z + 5;
    rt->clone.objects->point_b.z = rt->clone.objects->point_b.z + 5;
    rt->clone.objects->point_c.z = rt->clone.objects->point_c.z + 5;
}            if (keycode == 78)
{
    rt->clone.objects->point_a.z = rt->clone.objects->point_a.z - 5;
    rt->clone.objects->point_b.z = rt->clone.objects->point_b.z - 5;
    rt->clone.objects->point_c.z = rt->clone.objects->point_c.z - 5;
}
}
void    triangle_trans(t_minirt *rt,int keycode)
{
    if (keycode == 0)
        {
            rt->clone.objects->point_a.x = rt->clone.objects->point_a.x - 5;
            rt->clone.objects->point_b.x = rt->clone.objects->point_b.x - 5;
            rt->clone.objects->point_c.x = rt->clone.objects->point_c.x - 5;
        }
    if (keycode == 2)
        {
            rt->clone.objects->point_a.x = rt->clone.objects->point_a.x + 5;
            rt->clone.objects->point_b.x = rt->clone.objects->point_b.x + 5;
            rt->clone.objects->point_c.x = rt->clone.objects->point_c.x + 5;
        }
            if (keycode == 13)
{
    rt->clone.objects->point_a.y = rt->clone.objects->point_a.y + 5;
    rt->clone.objects->point_b.y = rt->clone.objects->point_b.y + 5;
    rt->clone.objects->point_c.y = rt->clone.objects->point_c.y + 5;
}  
triangle_trans1(rt,keycode);         
}

void        square_trans(t_minirt *rt, int keycode)
{
    if (keycode == 0)
        rt->clone.objects->sq_center.x = rt->clone.objects->sq_center.x - 5;
    if (keycode == 2)
        rt->clone.objects->sq_center.x = rt->clone.objects->sq_center.x + 5;
    if (keycode == 13)
        rt->clone.objects->sq_center.y = rt->clone.objects->sq_center.y + 5;
    if (keycode == 1)
        rt->clone.objects->sq_center.y = rt->clone.objects->sq_center.y - 5;
    if (keycode == 69)
        rt->clone.objects->sq_center.z = rt->clone.objects->sq_center.z + 5;
    if (keycode == 78)
        rt->clone.objects->sq_center.z = rt->clone.objects->sq_center.z - 5;
}