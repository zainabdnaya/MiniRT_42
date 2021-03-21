/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:12:53 by mac               #+#    #+#             */
/*   Updated: 2020/11/24 21:07:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

char                 **ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_stringdel(&(split[i]));
		i++;
	}
	free(*split);
	*split = NULL;
	return(split);
}