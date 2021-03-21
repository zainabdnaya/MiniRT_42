/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:33:22 by zdnaya            #+#    #+#             */
/*   Updated: 2021/03/21 23:09:47 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void		config_window(t_minirt *rt, double fov)
{
	double tetha;

	tetha = (fov) * (PI / 180);
	rt->aspectRatio = (double)rt->resol.WIDTH / (double)rt->resol.HEIGHT;
	rt->half_height = -1 * tan(tetha / 2) * 2;
	rt->half_width = 2 * tan(tetha / 2) * (rt->aspectRatio);
}

void		config_camera(t_minirt *rt, t_vector look_at)
{
	t_vector w;
	t_vector u;
	t_vector v;
	t_vector vup;

	vup = (t_vector){0, 1, 0};
	w = vectorscale(look_at, (-1));
	w = vectorNorme(w);
	u = vectorCross(vup, w);
	u = vectorNorme(u);
	v = vectorCross(w, u);
	calcul_direction(rt, w, u, v);
}

void		calcul_direction(t_minirt *rt, t_vector w, t_vector u, t_vector v)
{
	t_vector c;
	t_vector l;

	c = vectorsub(rt->list_camera->look_from, w);
	l.x = c.x - u.x * rt->half_width / 2 - v.x * rt->half_height / 2;
	l.y = c.y - u.y * rt->half_width / 2 - v.y * rt->half_height / 2;
	l.z = c.z - u.z * rt->half_width / 2 - v.z * rt->half_height / 2;
	rt->pixel_position.x = l.x + \
	u.x * rt->mlx.draw_x *\
	rt->half_width / rt->resol.WIDTH + \
	v.x * rt->mlx.draw_y *\
	rt->half_height / rt->resol.HEIGHT;
	rt->pixel_position.y = l.y + \
	u.y * rt->mlx.draw_x *\
	rt->half_width / rt->resol.WIDTH + \
	v.y * rt->mlx.draw_y *\
	rt->half_height / rt->resol.HEIGHT;
	rt->pixel_position.z = l.z + \
	u.z * rt->mlx.draw_x *\
	rt->half_width / rt->resol.WIDTH + \
	v.z * rt->mlx.draw_y *\
	rt->half_height / rt->resol.HEIGHT;
	rt->ray_direction = vectorsub(rt->pixel_position, \
	rt->list_camera->look_from);
	rt->ray_direction = vectorNorme(rt->ray_direction);
}
