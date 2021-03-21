/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:54:17 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:59:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int main(int argc,char **argv)
{
    t_minirt rt;

    if (argc < 2 || argc > 4)
    {
            error(1);
            exit(1);
    }
    if (ft_compare_end(argv[1], ".rt") != 1)
     {
           error(2);
           exit(1);
     }
    ft_bzero(&rt,sizeof(t_minirt));
     rt.name = argv[1];
     initial_all_objects(&rt);
     rt.stc.i = 1;
     rt.stc.j = 0;
     rt.stc.size = 0;
     if (argc == 3)
     {
         if(ft_compare_end(argv[2],"--save") == 1)
            rt.save = 1;
     }
    rt.mlx.mlx_ptr = mlx_init();
    parsing_rt(argv[1],&rt);
    create_window(&rt, rt.resol.WIDTH, rt.resol.HEIGHT);               
}