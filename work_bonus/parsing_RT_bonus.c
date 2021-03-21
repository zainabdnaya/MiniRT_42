/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_RT_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:48:53 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:59:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void configuration(t_minirt *rt)
{
  
    if (ft_samestr(rt->pars.splitrest[0], "R"))
        resolution_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "A"))
        ambient_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "c"))
        camera_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "l"))
        light_parsing(rt);
    else if (ft_samestr(rt->pars.splitrest[0], "sp"))
        sphere_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"pl"))
        plan_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"tr"))
            triangle_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"sq"))
            square_parsing(rt);
    else if(ft_samestr(rt->pars.splitrest[0],"cy"))
            cylindre_parsing(rt);
    else
            rt->here = 1;
}

void        parsing_rt1(t_minirt *rt)
{
    rt->pars.splitrest = ft_charSplit(rt->line, "\t\n\v\f ");
        if (rt->pars.splitrest[0] != NULL)
            {
                configuration(rt);
            }
        if (rt->here == 1 && rt->pars.splitrest[0][0] != '\0')
        {
            error(5);
            exit(1);
        }
        rt->pars.splitrest = ft_free_split(rt->pars.splitrest);
        ft_stringdel(&rt->line);
}

void parsing_rt(char *file, t_minirt *rt)
{
    int fd;
    int r;
    if ((fd = open(file, O_RDONLY)) < 0)
        {
            error(3);
            exit(1);
        }
    while ((r = get_next_line(fd, &rt->line)) > 0)
        parsing_rt1(rt);
    if(r == 0)
      parsing_rt1(rt);
    close(fd);
}