/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:54:26 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/27 15:57:30 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector rotation_1(char *str_to_convert, t_vector to_rotate)
{
    t_vector result;
    t_vector rotation_angle;

    rotation_angle = vectorSplit(str_to_convert);
    result = rotation(to_rotate, rotation_angle);
    return (result);
}