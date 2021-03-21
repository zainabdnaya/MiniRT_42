/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:45:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:56:26 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/minirt.h"

void      calcul_data(t_minirt *rt)
{
    if(rt->check == 1)
           calcul_sphere(rt);
    if (rt->check == 2) 
           calcul_plan(rt);
    if (rt->check == 3)
           calcul_triangle(rt);
     if (rt->check == 4)
           calcul_square(rt);            
    if (rt->check== 5)
            calcul_cylindre(rt);
    else
        return;
}

void  object_coloration(t_minirt *rt)
{
    t_list_lights *lgt;
    
    lgt = NULL;
    rt->Id.x = 0;
    rt->Id.y = 0;
    rt->Id.z = 0;
    rt->Spec.x = 0;
    rt->Spec.y = 0;
    rt->Spec.z = 0;
    lgt = rt->list_light;
    while(rt->list_light != NULL)
        {
            rt->result_color = rt->list_obj->color;
            rt->n_norm = rt->list_obj->normal;
            rt->position = rt->list_obj->position;
            rt->list_obj->light_norm = vectorsub(rt->list_light->position, rt->position);
            rt->ratio = rt->list_light->ratio; 
            rt->light_rgb = rt->list_light->rgb;
            rt->l_norm = vectorNorme(rt->list_obj->light_norm);
            rt->Id   = vectoradd(diffuse(rt),rt->Id);
            rt->Spec = vectoradd(spec(rt),rt->Spec);
            rt->list_light = rt->list_light->next;
        }
    rt->list_light = lgt;
}

void        objects_intersection(t_minirt *rt,t_vector ray_direction,t_vector look_from)
{
    if (rt->list_obj->wich_objects == 1)
        rt->var = sphere_equation(rt, ray_direction, look_from);
    if (rt->list_obj->wich_objects == 2)
        rt->var = plan_equation(rt,ray_direction,look_from);
    if (rt->list_obj->wich_objects == 3)
        rt->var = triangle_equation(rt, ray_direction,look_from);
    if (rt->list_obj->wich_objects == 4)
        rt->var = square_equation(rt,ray_direction,look_from);
    if (rt->list_obj->wich_objects == 5)
        rt->var = cylindre_equation(rt,ray_direction,look_from);
}

void        wich_object(t_minirt *rt,double *cmp)
{
    t_objects *tmp;
    
    rt->exist = 0;
    tmp = NULL;
    tmp = rt->list_obj;
    while( rt->list_obj != NULL)
    {
        objects_intersection(rt, rt->ray_direction, rt->list_camera->look_from);
        if (rt->var > 0.0 && rt->var < *cmp)
        {
            *cmp = rt->var;
            rt->list_obj->solution = *cmp;
            rt->check = rt->list_obj->wich_objects;
            rt->indice = rt->list_obj->objects_index;
            calcul_data(rt);
            object_coloration(rt);
            rt->exist = 1;
        }
        rt->list_obj  = rt->list_obj->next;
    }
    rt->list_obj =  tmp;
 }

t_color ray_Tracing(t_minirt *rt)
{
    double    cmp = INT_MAX; 
    t_color black = {0, 0, 0};
    t_color result1;
    rt->exist = 0;
    
    wich_object(rt,&cmp);
    if (rt->exist == 1)
     {  
         wich_shadow(rt);
         if(rt->percent_shadow > 1)
            rt->percent_shadow = 1;
        rt->percent_shadow = 1-rt->percent_shadow;
        result1.g = 255  * (ambiant(rt).y + rt->percent_shadow *(rt->Id.y  + rt->Spec.y ));
        result1.r = 255  * (ambiant(rt).x + rt->percent_shadow *( rt->Id.x + rt->Spec.x));
        result1.b = 255  * (ambiant(rt).z + rt->percent_shadow *(rt->Id.z  + rt->Spec.z ));
        result1.r = min(255, max(0, result1.r));
        result1.g = min(255, max(0, result1.g));
        result1.b = min(255, max(0, result1.b));
    }
    else
            result1 = black;
    return(result1);

}
