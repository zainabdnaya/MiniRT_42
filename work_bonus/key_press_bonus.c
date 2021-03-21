/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:49:22 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"


void     key_press_lights(int keycode, t_minirt *rt)
{
    if(rt->stc.j==0)
     {
        rt->new_lightTmp = rt->clone.lights;
        rt->stc.j = 1;
        rt->stc.size = ft_lstsize1(rt->new_lightTmp);
     }
    if(keycode == 126 && rt->active == 2)
    {
        if(rt->stc.size <= rt->stc.i)
        {
            rt->clone.lights = rt->new_lightTmp;
            rt->stc.i = 0;
        }
        else
            rt->clone.lights = rt->clone.lights->next;
        rt->stc.i++;
    }
    if (keycode == 125 && rt->active == 2 && rt->clone.lights->previous!= NULL )
                rt->clone.lights = rt->clone.lights->previous;
}



void     key_press_objects(int keycode, t_minirt *rt)
{
    if(rt->stc.j==0)
     {
        rt->new_Tmp=rt->clone.objects;
        rt->stc.j=1;
        rt->stc.size = ft_lstsize2(rt->new_Tmp);
     }
    if(keycode == 126 && rt->active == 3  )
    {
        if(rt->stc.size <= rt->stc.i)
        {
            rt->clone.objects=rt->new_Tmp;
            rt->stc.i=0; 
        }
        else
          rt->clone.objects= rt->clone.objects->next;
       rt->stc.i++;
    }
      if (keycode == 125 && rt->active == 3 && rt->clone.objects->previous!= NULL )
        rt->clone.objects = rt->clone.objects->previous;
}