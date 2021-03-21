/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_configue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:49:59 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/27 14:35:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void        mlx_hook_configuration(t_minirt *rt)
{
        mlx_key_hook(rt->mlx.win, key_hook, &rt->mlx);
        mlx_hook(rt->mlx.win,17,1L<<0,mlx_close,rt);
        mlx_hook(rt->mlx.win,2,1L<<0,key_press,rt);
}

void                 create_window(t_minirt *rt, int WIDTH, int HEIGHT)
{
      if (!(rt->mlx.win = mlx_new_window(rt->mlx.mlx_ptr, WIDTH, HEIGHT, rt->name)))
        {
            error(0);
            exit(1);
        }
    if (!(rt->mlx.img_ptr = mlx_new_image(rt->mlx.mlx_ptr, WIDTH, HEIGHT)))
       {
           error(0);
           exit(1);
       }
    if (!(rt->mlx.image = (int *)mlx_get_data_addr(rt->mlx.img_ptr, &rt->mlx.bpp, &rt->mlx.size_l, &rt->mlx.endian)))
    {
        error(0);
        exit(1);
    }
        init_graphics(rt);
}


void init_graphics(t_minirt *rt)
{ 
    if ( rt->save == 1)
    {
        build_image(rt, rt->list_camera->look_at);
        create_bmp(rt);
    }
    else
    {         
        build_image(rt, rt->list_camera->look_at);
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
        mlx_hook_configuration(rt);
        mlx_loop(rt->mlx.mlx_ptr);
    }  
}

