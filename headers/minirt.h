/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:06:47 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:59:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
#define MINI_RT

#include    "../minilibx_opengl_20191021/mlx.h"
#include    "../minilibx_mms_20200219/mlx.h"
#include    "get_next_line.h"
#include    "use.h"
#include    "objects.h"
#include    <stdlib.h>
#include    <unistd.h>
# include   <stdlib.h>
# include   <unistd.h>
# include   <stdarg.h>
# include   <string.h>
# include   <stdio.h>
#include    <math.h>
#include    <pthread.h>
#include    <errno.h>
#include    <sys/uio.h>
#include    <fcntl.h>
#include    <limits.h>
#define     Width 1000
#define     Height 800
#define     PI 3.14159


#define max(a, b) ((double)a >= (double)b ? (double)a : (double)b)
#define min(a, b) ((double)a <= (double)b ? (double)a : (double)b)


typedef struct s_list
{
    void             *content;
    struct s_list   *next;
}           t_list;

typedef struct s_mlx
{
    void        *mlx_ptr;
    void        *img_ptr;
    void        *win;
    int         *data_image;
    int         *image;
    int         size_l;
    int         bpp;
    int         endian;
    double      x;
    double      y;
    double      z;
    double      draw_x;
    double      draw_y;
} t_mlx;    

typedef     struct s_hit
{
    double  hit_sphere;
}  t_hit;

typedef struct s_objects
{
    t_vector    center;
    double      radius;
    t_color     color;
    double      solution;
    t_vector    position;
    t_vector    normal;
    t_vector    light_norm;
    t_vector    point;
    t_vector    p_norm;
    t_vector    point_a;
    t_vector    point_b;
    t_vector    point_c;
    t_vector    tr_normal;
    t_vector    sq_center;
    t_vector     cy_center;
    double      side_size;
    double      diameter;
    double      height;
    t_vector    cy_normal;
    int         objects_index;
    int         wich_objects;
    
    struct s_objects   *next;
    struct s_objects   *previous;
}t_objects;

typedef struct s_list_lights{

    double      intensity;
    t_vector    color;
    t_vector    position;
    double      ratio;
    t_color     rgb;

    struct s_list_lights *next;
    struct s_list_lights *previous;

}t_list_lights;

typedef struct s_list_camera{

    double      fov;
    t_vector    look_from;
    t_vector    look_at;
    t_vector    rotation;
    

    struct s_list_camera *next;
    struct s_list_camera *previous;
}t_list_camera;

typedef struct s_all
{
    t_list_lights   *lights;
    t_list_camera   *camera;
    t_objects       *objects;
}   t_all;

typedef struct  s_static
{
    int i;
    int j;
    int size;
}t_static;

typedef struct s_minirt
{
    t_mlx       mlx;
    t_vector    vect;
    t_ray       ray;
    t_color     color;
    t_vector    pixel_position;
    t_vector    ray_direction;
    t_pars      pars;
    t_resol     resol;
    t_ambient   ambient;
    t_phong     phong;
    t_camera    *cam;
    t_color     result_color;
    t_vector     l_norm;
    t_vector     n_norm;
    t_vector     position;
    t_color     color_result;
    t_vector     Id;
    t_vector     pol;
    t_vector     amb;
    t_vector     shadow_origin;
    t_color     light_rgb;
    t_vector     shadow_direction;
    t_vector     Spec;
    t_static       stc;

    t_objects       *list_obj;
    t_list_lights   *list_light;
    t_list_camera   *list_camera;
    t_list_camera   *new_camera;
    t_list_camera   *new_camtmp;
    t_list_lights   *new_lightTmp;
    t_objects       *new_Tmp;
    t_all           clone;



    char        *line;
    char        *name;
    
    int         save;
    int             wich_object;
    int             object_number;
    double          solution;
    double          aspectRatio;
    double          half_height;
    double          half_width;
    double          exist;
    double          hit1;
    double          m;
    int             check;
    double          ratio;
    double          hit_shadow;
    double          shadow;
    int             test;
    double          percent_shadow;
    double          var;
    double          shininess;
    double          ks;
    int             active;
    int             active_trans;
    int             active_rotation;
    int             now;
    int             i;
    int             j;
    int             size;
    int             index1;
    int             indice;
    int             sizex;
    int             sizey;
    int             trans_rot_index;
    int             axe;
    int             obj;
    int             switch_on;
    int             here;
}t_minirt;


/***********************Vectors *************************************/
t_vector        vectorSplit(char *str);
t_vector        vectoradd(t_vector v1, t_vector v2);
t_vector        vectorsub(t_vector v1, t_vector v2);
t_vector        vectorscale(t_vector v1, double m);
t_vector        vectordiv(t_vector v1, double d);
double          vectordot(t_vector v1, t_vector v2);
t_vector        vectorCross(t_vector v1, t_vector v2);
double          vectorLenght(t_vector v);
t_vector        vectorNorme(t_vector p);
t_vector        produit_Vect(t_vector v1, t_vector v2);
t_color         org(t_color r);
double          distance(t_vector one, t_vector two);
 /******************************************************************/

/*************Errors**********************************************/
void            error(double nbr);
void            p_error(long nbr1);
void            obj_error(long nbr);
void            other_errors(int nbr);

/******************************************************************/

/**************Window / Camera************************************/
void            init_graphics(t_minirt *rt);
void            config_window(t_minirt *rt,double fov);
void            config_camera(t_minirt *rt, t_vector look_at);
void            calcul_direction(t_minirt *rt, t_vector w, t_vector u, t_vector v);
void            build_image(t_minirt *rt, t_vector look_at);
void            create_window(t_minirt *rt, int WIDTH, int HEIGHT);
int	            mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/******************************************************************/

/**************Parsing *****************************************/
void            parsing_rt(char *file, t_minirt *rt) ;
void            configuration(t_minirt *rt);
void            resolution_parsing(t_minirt *rt);
void            ambient_parsing(t_minirt *rt);
void            camera_parsing(t_minirt *rt);
void            sphere_parsing(t_minirt *rt);
void            light_parsing(t_minirt *rt);
void            plan_parsing(t_minirt *rt);
void            triangle_parsing(t_minirt *rt);
void            square_parsing(t_minirt *rt);
void            cylindre_parsing(t_minirt *rt);
t_camera        *camera_one(t_camera *camera,t_minirt *rt);
t_plan          *paln_one(t_minirt *rt, t_plan *plan);
t_sphere *sphere_one(t_minirt *rt,t_sphere *sphere);
void        object_press(t_minirt *rt,int keycode);
void        parsing_rt1(t_minirt *rt);


/******************************************************************/

/*************Intersection  Objects ******************************/
double          sphere_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          plan_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          triangle_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin);
double          square_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          cylindre_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
/******************************************************************/

/**************************Objects*********************************/
void            calcul_sphere(t_minirt *rt);
void            calcul_plan(t_minirt *rt);
void            calcul_triangle(t_minirt *rt);
void            calcul_square(t_minirt *rt);
void            calcul_cylindre(t_minirt *rt);
void            initial_all_objects(t_minirt *rt);
void            objects_intersection(t_minirt *rt, t_vector ray_direction, t_vector look_from);
/******************************************************************/

/****************Phong*********************************************/
t_vector        spec(t_minirt *rt);
t_vector        ambiant(t_minirt *rt);
t_vector        diffuse(t_minirt *rt);
/******************************************************************/

/**********Colors**************************************************/
int            ft_color(double ir, double ig, double ib);
t_color        colorSplit( char *str);
void           object_coloration(t_minirt *rt);
void           light_coloration(t_minirt *rt,t_vector *l_norm,double *ratio,t_color *light_rgb);
/******************************************************************/

/***************Raytracing*****************************************/
t_color         ray_Tracing(t_minirt *rt);
t_color         hit_sphere(t_minirt *rt);
t_color         hit_objects(t_minirt *rt);
void            wich_object(t_minirt *rt,double *cmp);
void            calcul_data(t_minirt *rt);
/******************************************************************/

/***********************Linked_List  *******************************/
t_color         wich_object_color(t_minirt *rt);
void            add_list_back(t_list *(*head), t_list *last);
t_objects       *add_sphere_data(t_minirt *rt,t_vector center, double radius, t_color color);
void            add_objects(t_objects  **objs, t_objects  *new_obj);
double          counting_list(t_list *lst);
int             ft_countObjects(t_list *lst);
t_objects       *add_plan_data(t_minirt *rt,t_vector point,t_vector norm, t_color color);
t_objects       *add_triangle_data(t_minirt *rt,t_vector point_a, t_vector point_b, t_vector point_c, t_color color);
t_objects       *add_square_data(t_minirt *rt,t_vector center, t_vector normal, double side_size, t_color color);
t_objects       *add_cylindre_data(t_minirt *rt,t_vector center, t_vector normal,double diameter,double height,t_color color);
t_list_lights   *add_light_data(t_vector position, double ratio, t_color color_light);
void            add_lights(t_list_lights **head, t_list_lights *new_obj);
t_list_camera   *add_camera_data(t_vector look_from,t_vector look_at,double fov);
void            add_camera(t_list_camera **head, t_list_camera *new_obj);
int		        ft_lstsize(t_list_camera *lst);
int		        ft_lstsize1(t_list_lights *lst);
int		ft_lstsize2(t_objects *lst);
/**********************************************************************/
int             create_bmp(t_minirt *rt);
/*************************TOOLS***************************************/
int            ft_compare_end(char *str, char *end);
int            ft_count(char **str);
void           ft_node_back(t_list **head, t_list *next);
t_list         *creat_new_node(void *data);
int            ft_charCount(char *str, char c);
void           ft_stringdel(char **string);
char           **ft_free_split(char **split);
char           **ft_charSplit(char const *s, char *set);
double         convert_to_double(char *string) ;
int            ft_samestr(char *s1, char *s2);
int            resol_check(char *resolution);
double         my_power(double number, int power);
int            ft_atoi(char *str);
char           **ft_split(char *s, char c);
int            ft_isdigit(int c);
char           *ft_strdup(char *src);
unsigned int    ft_strlen(const char *s);
char            *ft_strjoin(char const *s1, char const *s2);
int             digits_only(char *s);
/***********************************************************************/

/*************************Shadows***************************************/
void            wich_shadow(t_minirt *rt);
double          check_shadow(t_minirt *rt);
void            shadow_objects(t_minirt *rt);
void            shadow_intersection(t_minirt *rt, t_vector shadow_direction, t_vector shadow_origin);
void            specular_data(t_minirt *rt);
t_vector postion_shadow(double solution, t_vector origin, t_vector direction);
    /***********************************************************************/
    void print_list_sphere(t_objects *ip);
void            print_list_pal(t_objects *ip);
void            print_list_tr(t_objects *ip);
void            print_light(t_list_lights *light);
void            print_light1(t_minirt *rt);
/***********************************************************************/
/******************** mlx_hook******************************************/
int             mlx_close(t_minirt *rt);
int             key_hook(int key, t_minirt *rt);
void            mlx_hook_configuration(t_minirt *rt);
int             key_press(int keycode, t_minirt *rt);
void            key_press2(int keycode,t_minirt *rt);
void            key_press_camera(int keycode, t_minirt *rt);
void            camera_press(t_minirt *rt,int keycode);
void            camera_rotation(t_minirt *rt,int axe,int keycode);   
void            light_press(t_minirt *rt,int keycode);
void            key_press_lights(int keycode, t_minirt *rt);
void            key_press4(int keycode, t_minirt *rt);
void            cam_rot(t_minirt *rt,int keycode);
void            key_press5(int keycode, t_minirt *rt);
void            key_press6(int keycode, t_minirt *rt);
void            wich_one(t_minirt *rt, int keycode);
void            wich_axe(t_minirt *rt,int keycode);
void            key_press_objects(int keycode, t_minirt *rt);
void            key_press8(int keycode,t_minirt *rt);
void        triangle_trans1(t_minirt *rt,int keycode);     

/***********************************************************************/

/**************************translation&rotation****************************************/
void        camera_translation(t_minirt *rt,int keycode);
t_vector    rotation_around_x(t_vector vector_to_rotate,double  tetha);
t_vector    rotation_around_y(t_vector vector_to_rotate,double  tetha);
t_vector    rotation_around_z(t_vector vector_to_rotate,double  tetha);
t_vector    radian_in(t_vector rotation);
t_vector    rotation(t_vector vector_to_rotate,t_vector rotation);
t_vector    translation(char *str_to_convert,t_vector add_in);
t_vector    rotation_1(char *str_to_convert,t_vector to_rotate);
void        light_translation(t_minirt *rt,int keycode);
void        sphere_translation(t_minirt *rt,int keycode);
void        cylindre_trans(t_minirt *rt,int keycode);
void        cylindre_rot(t_minirt *rt,int axe,int keycode);
void        plan_trans(t_minirt *rt, int keycode);
void        plan_rot(t_minirt *rt, int axe, int keycode);
void        triangle_trans(t_minirt *rt, int keycode);
void        square_trans(t_minirt *rt, int keycode);
void        objects_trans(t_minirt *rt,int keycode);
void        objects_rot(t_minirt *rt,int keycode);
void        plan_rot(t_minirt *rt, int axe, int keycode);
void        square_rot(t_minirt *rt, int axe, int keycode);


#endif // DEBUGs