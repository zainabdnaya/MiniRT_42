/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:06:57 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector vectoradd(t_vector v1, t_vector v2)
{
    t_vector w;

    w.x = v1.x + v2.x;
    w.y = v1.y + v2.y;
    w.z = v1.z + v2.z;
    return (w);
}

t_vector vectorsub(t_vector v1, t_vector v2)
{
    t_vector w;

    w.x = v1.x - v2.x;
    w.y = v1.y - v2.y;
    w.z = v1.z - v2.z;
    return (w);
}

t_vector vectorscale(t_vector v1, double m)
{
    t_vector w;

    w.x = v1.x * m;
    w.y = v1.y * m;
    w.z = v1.z * m;
    return (w);
}

t_vector vectordiv(t_vector v1, double d)
{
    t_vector w;

    w.x = v1.x / d;
    w.y = v1.y / d;
    w.z = v1.z / d;
    return (w);
}

double vectordot(t_vector v1, t_vector v2)
{
    double m;

    m = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return (m);
}
