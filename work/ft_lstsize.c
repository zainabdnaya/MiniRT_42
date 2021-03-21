/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:09:24 by mac               #+#    #+#             */
/*   Updated: 2020/11/27 15:52:07 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int		ft_lstsize(t_list_camera *lst)
{
	int		count;
	t_list_camera	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int list_size(t_objects *list)
{
	int count;

	count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}
