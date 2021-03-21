/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:37:18 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:56:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector radian_in(t_vector rotation)
{
    rotation = vectorscale(rotation,-1);
    rotation.x = rotation.x * (PI / 180);
    rotation.y = rotation.y * (PI / 180);
    rotation.z = rotation.z * (PI / 180);
    return (rotation);
}

t_vector    rotation_around_x(t_vector vector_to_rotate,double  tetha)
{
    t_vector vect;
    
    vect = vector_to_rotate;
    vect.x = vector_to_rotate.x;
    vect.y = vector_to_rotate.y * cos(tetha) + vector_to_rotate.z * sin(tetha) ;
    vect.z = vector_to_rotate.z * cos(tetha) - vector_to_rotate.y * sin(tetha);
    return(vect);
}

t_vector    rotation_around_y(t_vector vector_to_rotate,double  tetha)
{
    t_vector vect;
    
    vect = vector_to_rotate;
    vect.x = vector_to_rotate.x * cos(tetha) - vector_to_rotate.z * sin(tetha);
    vect.y = vector_to_rotate.y;
    vect.z =  vector_to_rotate.x * sin(tetha) +vector_to_rotate.z * cos(tetha);
    return(vect);
}

t_vector    rotation_around_z(t_vector vector_to_rotate,double  tetha)
{
    t_vector vect;
    
    vect = vector_to_rotate;
    vect.x = vector_to_rotate.x * cos(tetha) + vector_to_rotate.y * sin(tetha);
    vect.y = vector_to_rotate.y * cos(tetha) - vector_to_rotate.x  * sin(tetha);
    vect.z = vector_to_rotate.z;
    return(vect);
}

t_vector    rotation(t_vector vector_to_rotate,t_vector rotation)
{
    t_vector vect;

    rotation =  radian_in(rotation);
    vector_to_rotate = rotation_around_x(vector_to_rotate,rotation.x);
    vect = vector_to_rotate;
    vector_to_rotate = rotation_around_y(vector_to_rotate,rotation.y);
    vect = vector_to_rotate;
    vector_to_rotate = rotation_around_z(vector_to_rotate,rotation.z);
    vect = vector_to_rotate;
    vect = vectorNorme(vect);
    return(vect);
}

