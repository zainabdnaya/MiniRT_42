/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:13:54 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:17:34 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void wich_axe(t_minirt *rt,int keycode)
{
    if( keycode == 7) //x
            rt->axe = 1;
        if(keycode == 16) //y
            rt->axe = 2;
        if(keycode == 6) //z
            rt->axe = 3;
} 


void          light_press(t_minirt *rt,int keycode)
{
    key_press_lights(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(rt->trans_rot_index == 1  )
    {   
        light_translation(rt,keycode);
        build_image(rt, rt->list_camera->look_at);
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }   
}

void        cam_rot(t_minirt *rt,int keycode)
{
        wich_axe(rt,keycode);
        if(rt->axe == 1 || rt->axe == 2 || rt->axe == 3)
            camera_rotation(rt,rt->axe,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);   
}
void          camera_press(t_minirt *rt,int keycode)
{
  
    key_press_camera(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(keycode == 15)
        rt->trans_rot_index= 2;
    if(rt->trans_rot_index == 1 )
    {   
        camera_translation(rt,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
    if(rt->trans_rot_index == 2)
        cam_rot(rt,keycode);
}

