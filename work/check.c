/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:15:53 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/27 13:01:54 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int resol_check(char *resolution)
{
    int i;
    int result;
    
    i = 0;
    while (resolution[i] != '\0')
    {
        if (ft_isdigit(resolution[i]) == 1)
            result = 1;
        else
        {
            result = 0;
            break;
        }

        i++;
    }
    return (result);
}