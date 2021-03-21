/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:45:56 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:16:43 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void		bmp_file_header(t_minirt *rt, int *fd)
{
	int file_size;
	int first_pix;

	file_size = 14 + 40 + 4 + (rt->resol.WIDTH * rt->resol.HEIGHT) * 4;
	first_pix = 14 + 40 + 4;
	write(*fd, "BM", 2);
	write(*fd, &file_size, 4);
	write(*fd, "\0\0\0\0", 4);
	write(*fd, &first_pix, 4);
}

void		bmp_file_info_header(t_minirt *rt, int *fd)
{
	int header_info_size;
	int plane_nbr;
	int count;

	header_info_size = 40;
	plane_nbr = 1;
	count = 0;
	write(*fd, &header_info_size, 4);
	write(*fd, &rt->resol.WIDTH, 4);
	write(*fd, &rt->resol.HEIGHT, 4);
	write(*fd, &plane_nbr, 2);
	write(*fd, &rt->mlx.bpp, 2);
	while (count < 28)
	{
		write(*fd, "\0", 1);
		count++;
	}
}

static void	copy_data(t_minirt *rt, int *fd)
{
	int i;

	i = rt->resol.WIDTH * rt->resol.HEIGHT;
	while (i > 0)
	{
		write(*fd, &rt->mlx.image[i], 4);
		i--;
	}
}

void		pixel_data(t_minirt *rt, int *fd)
{
	int i;
	int size_line;
	int save;
	int p;

	i = 0;
	rt->mlx.size_l /= 4;
	while (i < rt->resol.HEIGHT)
	{
		p = 0;
		size_line = rt->mlx.size_l;
		while (p < size_line && p != size_line)
		{
			save = rt->mlx.image[p + (i * rt->mlx.size_l)];
			rt->mlx.image[p + (i * rt->mlx.size_l)] =
				rt->mlx.image[size_line + (i * rt->mlx.size_l - 1)];
			rt->mlx.image[size_line + (i * rt->mlx.size_l - 1)] = save;
			p++;
			size_line--;
		}
		i++;
	}
	copy_data(rt, fd);
}

int			create_bmp(t_minirt *rt)
{
	int fd;

	fd = open("minirt.bmp", O_CREAT | O_RDWR);
	if (fd < 0)
	{
		error(31);
		exit(1);
	}
	bmp_file_header(rt, &fd);
	bmp_file_info_header(rt, &fd);
	pixel_data(rt, &fd);
	return (1);
}
