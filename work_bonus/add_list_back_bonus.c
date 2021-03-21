/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_back_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:14:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:25 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void add_list_back(t_list *(*head), t_list *last)
{
    t_list *tmp;

    if (!head || !last)
        return;
    if (*head)
    {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = last;
    }
    else
        *head = last;
}