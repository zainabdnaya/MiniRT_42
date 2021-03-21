/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:33:22 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:56:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"


void config_window(t_minirt *rt, double fov)
{
    double tetha;

    tetha = (fov) * (PI / 180);
    rt->aspectRatio = (double) rt->resol.WIDTH  / (double)rt->resol.HEIGHT;
    rt->half_height = -1 * tan(tetha / 2) *2;
    rt->half_width =   2 * tan(tetha / 2) * (rt->aspectRatio);
}

void config_camera(t_minirt *rt,t_vector look_at)
{
    t_vector w;
    t_vector u;
    t_vector v;
    t_vector vup = {0, 1, 0};
    w = vectorscale(look_at,(-1));
    w = vectorNorme(w);
    u = vectorCross(vup,w);
    u = vectorNorme(u);
    v = vectorCross(w,u);
    calcul_direction( rt, w, u,v);
}


void  calcul_direction(t_minirt *rt, t_vector w, t_vector u,t_vector v)
{
    t_vector C;
    t_vector L;
    C.x = rt->list_camera->look_from.x - w.x;
    C.y = rt->list_camera->look_from.y - w.y;
    C.z = rt->list_camera->look_from.z - w.z;
    L.x = C.x - u.x * rt->half_width / 2 - v.x * rt->half_height / 2;
    L.y = C.y - u.y * rt->half_width / 2 - v.y * rt->half_height / 2;
    L.z = C.z - u.z * rt->half_width / 2 - v.z * rt->half_height / 2;
    rt->pixel_position.x = L.x + u.x * rt->mlx.draw_x * rt->half_width / rt->resol.WIDTH + v.x * rt->mlx.draw_y * rt->half_height / rt->resol.HEIGHT;
    rt->pixel_position.y = L.y + u.y * rt->mlx.draw_x * rt->half_width / rt->resol.WIDTH + v.y * rt->mlx.draw_y * rt->half_height / rt->resol.HEIGHT;
    rt->pixel_position.z = L.z + u.z * rt->mlx.draw_x * rt->half_width / rt->resol.WIDTH + v.z * rt->mlx.draw_y * rt->half_height / rt->resol.HEIGHT;
    rt->ray_direction = vectorsub(rt->pixel_position,rt->list_camera->look_from);
    rt->ray_direction= vectorNorme(rt->ray_direction);
}