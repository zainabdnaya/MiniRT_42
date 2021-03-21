/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:35:49 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

t_vector vectorSplit(char *str)
{
    t_vector w;
    char **split;

    split = ft_split(str, ',');
    if (ft_count(split) != 3 || ft_charCount(str, ',') != 2)
    {
        ft_free_split(split);
        p_error(11);
        exit(1);
    }
    w.x = convert_to_double(split[0]);
    w.y = convert_to_double(split[1]);
    w.z = convert_to_double(split[2]);
    ft_free_split(split);
    return (w);
}

t_color  org(t_color r)
{
      t_color  result = {r.r / 255, r.g / 255, r.b / 255};
      return (result);
}


void        initial_all_objects(t_minirt *rt)
{
            rt->wich_object = 0;
            rt->object_number = 0;
            rt->solution = 0;
            rt->aspectRatio = 0;
            rt->half_height = 0;
            rt->half_width = 0;
            rt->exist = 0;
            rt->hit1 = 0;
            rt->m = 0;
            rt->check = 0;
            rt->ratio = 0;
            rt->hit_shadow = 0;
            rt->shadow = 0;
            rt->test = 0;
            rt->percent_shadow = 0;
            rt->var = 0;
            rt->shininess = 0;
            rt->ks = 0;
            rt->now = 0;
            rt->here = 0;
            rt->axe = 0;
            rt->obj = 0;
            rt->trans_rot_index = 0;
            rt->switch_on = 0;
}