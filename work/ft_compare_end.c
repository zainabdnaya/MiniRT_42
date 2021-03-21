/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:46:14 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 21:07:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int ft_compare_end(char *str, char *end)
{
    int i;
    int j;

    i = ft_strlen(str) - 1;
    j = ft_strlen(end) - 1;
    if (i < j)
        return (0);
    while (str[i] && end[j])
    {
        if (str[i] != end[j])
            return (0);
        j--;
        i--;
    }
    return (1);
}