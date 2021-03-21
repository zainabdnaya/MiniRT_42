/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:29:40 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/27 23:31:35 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"
#include <unistd.h>

void        shadow_intersection(t_minirt *rt,t_vector shadow_direction,t_vector shadow_origin)
{
    if (rt->list_obj->wich_objects == 1 )
        rt->hit_shadow = sphere_equation(rt, shadow_direction,shadow_origin);
    else if (rt->list_obj->wich_objects == 2)
            rt->hit_shadow = plan_equation(rt, shadow_direction, shadow_origin);
    else if (rt->list_obj->wich_objects == 3 )
        rt->hit_shadow = triangle_equation(rt, shadow_direction,shadow_origin);
    else if (rt->list_obj->wich_objects == 4)
        rt->hit_shadow = square_equation(rt, shadow_direction,shadow_origin);
    else if (rt->list_obj->wich_objects == 5)
        rt->hit_shadow = cylindre_equation(rt,shadow_direction, shadow_origin);
 }

void       shadow_objects(t_minirt *rt)
{
       t_objects *tmp;
       int i;

        i = 0;
       tmp = NULL;
        tmp = rt->list_obj;
         while( rt->list_obj != NULL)
             { 
                 if(i == rt->indice )
                      rt->list_obj = rt->list_obj->next;
                if(rt->list_obj != NULL)
                {
                 shadow_intersection(rt,rt->shadow_direction,rt->shadow_origin);
                 if (rt->hit_shadow > 0.0)
                    {
                        if (rt->hit_shadow < distance(rt->list_light->position, rt->position) )
                        {
                             rt->percent_shadow += 0.4;
                             break;
                        }
                            else
                                    rt->shadow = 0;
                    }
                rt->list_obj = rt->list_obj->next;
             }
                i++;
            }
        rt->list_obj =  tmp;
}


void       wich_shadow(t_minirt *rt)
{
        t_list_lights *lgt;
        lgt = rt->list_light;
        rt->hit_shadow = 0;
        rt->shadow = 0;
        rt->percent_shadow =0;
        while(rt->list_light != NULL)
            {
                rt->shadow_origin.x = rt->position.x + 0.01 * rt->list_obj->normal.x;
                rt->shadow_origin.y = rt->position.y + 0.01 * rt->list_obj->normal.y;
                rt->shadow_origin.z = rt->position.z + 0.01 * rt->list_obj->normal.z;
                rt->shadow_direction.x = rt->list_light->position.x - rt->position.x;
                rt->shadow_direction.y = rt->list_light->position.y - rt->position.y;
                rt->shadow_direction.z = rt->list_light->position.z - rt->position.z;
                rt->shadow_direction = vectorNorme(rt->shadow_direction);
                shadow_objects(rt);
                  
                rt->list_light = rt->list_light->next;
           }
        rt->list_light = lgt;        
}

t_vector        postion_shadow(double solution,t_vector origin,t_vector direction)
{
    t_vector result;
    result.x = origin.x + solution * direction.x;
    result.y = origin.y + solution * direction.y;
    result.z = origin.z + solution * direction.z;
    return(result);
}