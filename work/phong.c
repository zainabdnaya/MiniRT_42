/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:52:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:58:19 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


t_vector ambiant(t_minirt *rt)
{
    t_vector amb;

    amb.x = rt->ambient.color.r * rt->ambient.ratio * rt->result_color.r;
    amb.y = rt->ambient.color.g * rt->ambient.ratio * rt->result_color.g;
    amb.z = rt->ambient.color.b * rt->ambient.ratio * rt->result_color.b;    
    amb.x = min(1, amb.x);  
    amb.y = min(1, amb.y);
    amb.z = min(1, amb.z);
    return (amb);
}

t_vector diffuse(t_minirt *rt)
{
    t_vector Id;
    double m;

    m = vectordot(rt->l_norm, rt->n_norm);
    m = max(0.0,m);
    Id.x = rt->ratio  * m *  rt->result_color.r * rt->light_rgb.r ;
    Id.y = rt->ratio  * m *  rt->result_color.g * rt->light_rgb.g ;
    Id.z = rt->ratio  * m *  rt->result_color.b * rt->light_rgb.b ;
    return (Id);
}

void        specular_data(t_minirt *rt)
{
    if(rt->check ==2  || rt->check == 3 || rt->check == 4)
    {
        rt->shininess = 10;
        rt->ks = 0.2;
    }
    else if (rt->check == 5)
    {
        rt->shininess = 500;
        rt->ks = 0.5;
    }
    else if (rt->check == 1)
    {
        rt->shininess = 500;
        rt->ks = 0.5;
    }
}


t_vector spec(t_minirt *rt)
{
    double dot;
    t_vector scal;
    t_vector specular;
    t_vector reflection;
    t_vector view;

    dot = 2 * vectordot(rt->n_norm, rt->l_norm);
    scal = vectorscale(rt->n_norm, dot);
    reflection = vectorsub(scal,rt->l_norm );
    reflection = vectorNorme(reflection);
    view = vectorscale(rt->ray_direction, -1);
    view = vectorNorme(view);
    dot = vectordot(reflection, view);
    dot = max(0.0,dot);
    specular_data(rt);
    specular.x = rt->ks * rt->light_rgb.r * pow(dot, rt->shininess) ;
    specular.y = rt->ks * rt->light_rgb.g * pow(dot, rt->shininess) ;
    specular.z = rt->ks * rt->light_rgb.b * pow(dot, rt->shininess) ;
    return (specular);
}
