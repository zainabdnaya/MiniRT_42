/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_power_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:46:55 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

double my_power(double number, int power)
{
    double result;
    int count;

    count = 1;
    result = 1;
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    while (count <= power)
    {
        result = result * number;
        count++;
    }
    return (result);
}