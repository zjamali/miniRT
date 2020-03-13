/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:05:13 by zjamali           #+#    #+#             */
/*   Updated: 2020/03/13 18:58:13 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#define max(a,b) ((double)a > (double)b ? (double)a : (double)b)
#define min(a,b) ((double)a > (double)b ? (double)b : (double)a)
#define PI 3.1415926535897932
typedef struct s_vector
{
	float x,y,z;
}t_vector;

typedef struct s_sphere
{
	t_vector origin;
	double  radius;
	t_vector color;
}t_sphere;

typedef struct s_ray
{
	t_vector origin;
	t_vector direction;
}t_ray;

typedef struct  s_camera
{
	t_vector lookfrom;
	t_vector orientaion;
	double fov;
}t_camera;
typedef struct  s_object
{
	void *object;
	t_vector *color;
	t_vector origin;
	char object_type;
	struct s_object *next;
}t_object;

typedef struct  s_scene
{
	int lenght; // how many object not including cam and light 
	t_object *objects;
	t_camera *cm;
}t_scene;

typedef struct s_ambient
{
	double intensity;
	t_vector color;
}t_ambient;

typedef struct s_light
{
	t_vector origin;
	double intensity;
	t_vector color;
}t_light;
/***********************  VECTOR.C  ***********************/
t_vector  vectorsadd(t_vector *v1,t_vector *v2);
t_vector vectorscal(t_vector *v ,double s);
t_vector vectordiv(t_vector *v, double d);
t_vector vectorsSub(t_vector *v1, t_vector *v2);
double vectorsDot(t_vector *v1, t_vector *v2);
double lenght(t_vector *v);
t_vector normalize(t_vector *v);
t_vector vectorsproduit(t_vector *v1,t_vector *v2);
t_vector vecttorscross(t_vector *v1,t_vector *v2);


/***********************  CAMERA.C  ***********************/
t_vector ft_camera(t_camera camera,double H,double W,double x,double y);


/***********************  INTERSECTION.C  ***********************/
double hit_sphere(t_ray ray,t_sphere *s);


/***********************  LIGHT.C  ***********************/
t_vector ft_specular(t_light *light,t_ray ray,double t,t_object *object);
t_vector ft_diffuse(t_light *light,t_ray ray,double t,t_object *object,t_vector *colors);
t_vector ft_ambient(t_ambient *ambient,t_vector *color);
t_vector ft_shadow(t_object *temp,t_object *object,t_light *light,t_ray ray,double t);

/***********************  PIXEL_COLOR.C  ***********************/
int ft_color_of_pixel(t_ray ray,t_object *object,t_ambient *ambient,t_light *light);
double rgbconvert(int ir, int ig, int ib);


