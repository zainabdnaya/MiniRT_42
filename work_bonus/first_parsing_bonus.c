/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:05:29 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:56:08 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void resolution_parsing(t_minirt *rt)
{
    int count;
    
    mlx_get_screen_size(rt->mlx.mlx_ptr,&rt->sizex,&rt->sizey);
    count = ft_count(rt->pars.splitrest);
    if (count != 3)
       {
           error(8);
           exit(1);
       } 
    rt->resol.WIDTH = ft_atoi(rt->pars.splitrest[1]);
    rt->resol.HEIGHT = ft_atoi(rt->pars.splitrest[2]);
    if ((rt->resol.WIDTH < 1) || (  rt->resol.HEIGHT < 1))
    {
        error(7);
        exit(1);
    }
    rt->resol.WIDTH= (rt->resol.WIDTH >= rt->sizex) ? rt->sizex : rt->resol.WIDTH;
   rt->resol.HEIGHT = (rt->resol.HEIGHT >= rt->sizey) ? rt->sizey : rt->resol.HEIGHT;
    
}

t_camera    *camera_one(t_camera *camera,t_minirt *rt)
{
    if (!(camera = malloc(sizeof(t_camera))))
    {
        free(camera);
        p_error(13);
        exit(1);
    }
    camera->look_from = vectorSplit(rt->pars.splitrest[1]);
    camera->look_at = vectorSplit(rt->pars.splitrest[2]);
    if ((camera->look_at.x > 1 || camera->look_at.x < -1) || (camera->look_at.y > 1 || camera->look_at.y < -1) || (camera->look_at.z > 1 || camera->look_at.z < -1))
    {
        obj_error(24);
        exit(1);
    }
    camera->fov = ft_atoi(rt->pars.splitrest[3]);
    if(camera->fov < 0 || camera->fov > 180)
    {
        error(7);
        exit(1);
    }
    return(camera);
}

void camera_parsing(t_minirt *rt)
{
    t_camera *camera;
    
    camera = NULL;
    if(ft_count(rt->pars.splitrest) == 4)
    { 
       camera = camera_one(camera,rt);
    }
    else if ( ft_count(rt->pars.splitrest) == 6 )
    {  
               camera = camera_one(camera,rt);
    camera->look_from = translation(rt->pars.splitrest[4], camera->look_from);
    camera->look_at = rotation_1(rt->pars.splitrest[5],camera->look_at);   
    }
    else
     {
        free(camera);
        p_error(10);
        exit(1);
    }
    add_camera(&rt->list_camera,add_camera_data(camera->look_from,camera->look_at,camera->fov));
    free(camera);
}

void ambient_parsing(t_minirt *rt)
{
    if (ft_count(rt->pars.splitrest) != 3)
       {
           p_error(16);
           exit(1);
       }
    rt->ambient.ratio = convert_to_double(rt->pars.splitrest[1]);
    rt->ambient.color = colorSplit( rt->pars.splitrest[2]);
    if (rt->ambient.ratio > 1 || rt->ambient.ratio < 0)
        {
            p_error(17);
            exit(1);
        }
}

void light_parsing(t_minirt *rt)
{
    t_light *light;

    if (!(light = malloc(sizeof(t_light))))
       {
           free(light);
           p_error(13);
           exit(1);
       } 
    if (ft_count(rt->pars.splitrest) != 5)
    {
        free(light);
        p_error(15);
        exit(1);
    }
    light->position = vectorSplit(rt->pars.splitrest[1]);
    light->ratio = convert_to_double(rt->pars.splitrest[2]);
    light->rgb = colorSplit( rt->pars.splitrest[3]);
    if (light->ratio > 1 || light->ratio < 0)
        {
            p_error(20);
            exit(1);
        }
    light->translation = vectorSplit(rt->pars.splitrest[4]);
    light->position = vectoradd(light->position,light->translation);
    add_lights(&rt->list_light,add_light_data(light->position,light->ratio,light->rgb));
    free(light);
}
