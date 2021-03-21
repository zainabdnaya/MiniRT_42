/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:00:02 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 00:06:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void error(double nbr)
{
    if (nbr == 0)
        write(2, "Error(0):\n Failed to Initial Minilibx", 41);
    if (nbr == 1)
        write(2, "Error(1):\n Wrong Number of Arguments!\n", 39);
    if (nbr == 2)
        write(2, "Error(2):\n Extension (.rt) needed! \n", 36);
    if (nbr == 3)
        write(2, "Error(3):\n There is No such file or directory!\n", 46);
    if (nbr == 4)
        write(2, "Error(4):\n Invalid extension!\n", 26);
    if (nbr == 5)
        write(2, "Error(5):\n Parsing error in file !\n", 36);
    if (nbr == 6)
        write(2, "Error(6):\n Small Resolution!\n", 29);
    if (nbr == 7)
        write(2, "Error(7:)\nfov should be in rage of [1,180]\n", 46);
    if (nbr == 8)
        write(2, "Error(8):\n Allocation failed !\n", 34);
    if (nbr == 9)
        write(2, "Error(9):\n No Resolution !\n", 29);
    if (nbr == 0.1)
        write(2, "Error(0.1):\n Try Integer type resolution!\n", 51);
}

void p_error(long nbr1)
{
    if (nbr1 == 10 )
        write(2, "Error(10):\nCheck Camera configuration is wrong!\n", 48);
    if (nbr1 == 11)
        write(2, "Eroor(11):\n Vector Parsing is wrong!\n", 38);
    if (nbr1 == 12)
        write(2, "Error(12):\n No Camera !\n", 20);
    if (nbr1 == 13)
        write(2, "Error(13):\n Allocation failed!\n", 35);
    if (nbr1 == 14)
        write(2, "Error(14):\n Problem in light parsing!\n", 45);
    if (nbr1 == 15)
        write(2, "Error(15):\n light Parsing is wrong!\n", 34);
    if (nbr1 == 16)
        write(2, "Error(16):\n Ambient Parsing is wrong!\n", 41);
    if (nbr1 == 17)
        write(2, "Error(17):\n Ambient Ratio  is wrong!\n", 43);
    if (nbr1 == 18)
        write(2, "Error(18):\n put 3 variables in a forme of vector and split it with 2 comma!\n", 76);
    if (nbr1 == 19)
        write(2, "Error(19):\n the number of RGB color should be in range [0,255]\n", 80);
    if (nbr1 == 20)
        write(2, "Error(20)\n:light Ratio  is wrong!\n", 43);
}

void obj_error(long nbr)
{
    if (nbr == 21)
        write(2, "Error(21):\n Sphere configuration is wrong!\n", 44);
    if (nbr == 22)
        write(2, "Error(22):\n Enter positive radius in sphere\n", 50);
    if(nbr == 23)
        write(2, "Error(23):\n Allocation objects failed!\n", 44);
    if(nbr == 24)
        write(2,"Error(24):\n The Normale Coordinates should be between [-1,1]",60);
    if (nbr == 25)
        write(2, "Error(25):\nPlan configuration is wrong!\n", 40);  
    if (nbr == 26)
        write(2, "Error(26):\n Triangle configuration is wrong!\n", 47);
    if (nbr == 27)
        write(2, "Error(27):\n square configuration is wrong!\n", 47);
    if (nbr == 28)
        write(2, "Error(28):\ncylindre configuration is wrong!\n", 45);
    if (nbr == 29)
        write(2, "Error(29):\nEnter positive diametre and height in cylindre\n", 59);
    if (nbr == 30)
        write(2,"Error(30):\nEnter positive Side_size is negative\n",50);
    if (nbr == 31)
        write(2,"Error(31):\nAccess denied \n",20);
}

void       other_errors(int nbr)
{
        if (nbr == 01)
        write(2,"Error(01):\n Only digits are allowed\n",35);
}