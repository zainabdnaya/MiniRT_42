/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:31:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 16:44:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int ft_color(double ir, double ig, double ib)
{
    int RGB = (ir * 65536) + (ig * 256) + ib;
    return (RGB);
}

t_vector color_percentage(t_vector r)
{
    t_vector result = {r.x / 255, r.y / 255, r.z / 255};
    return (result);
}

t_color colorSplit( char *str)
{
    double x;
    double y;
    double z;
    t_color color;
    char **result;

    result = ft_split(str, ',');
    if (ft_count(result) != 3 || ft_charCount(str, ',') != 2)
    {
        ft_free_split(result);
        p_error(18);
        exit(1);
    }
    x = convert_to_double(result[0]);
    y = convert_to_double(result[1]);
    z = convert_to_double(result[2]);
    if (x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255)
    {
        p_error(19);
        exit(1);
    }
    color.r = x / 255;
    color.g = y /255;
    color.b = z /255;
    ft_free_split(result);
    return (color);
}