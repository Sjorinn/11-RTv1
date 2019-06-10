/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:18:42 by gfranco           #+#    #+#             */
/*   Updated: 2019/06/10 15:38:22 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
//# include "../libft/libft.h"
# include "macros.h"
# include <math.h>
# include <stdio.h>
# include "../X-Libft/includes/libft.h"

# define WIDTH 1200
# define HEIGHT 1200

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			tab[3];
}				t_color;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		tab[3];
}				t_vector;

typedef struct	s_light
{
	t_vector	src;
	t_vector	ray;
	t_color		color;
}				t_light;

typedef struct	s_ray
{
	t_vector	dir;
	t_vector	origin;
}				t_ray;

typedef struct	s_sphere
{
	t_color		color;
	t_vector	center;
	double		radius;
}				t_sphere;

typedef struct	s_cone
{
	t_vector	tip;
	t_color		color;
	t_vector	b_center;
	double		b_radius;
}				t_cone;

typedef struct	s_plane
{
	t_color		color;
	t_vector	point;
	t_vector	normal;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	dir;
	t_color		color;
	t_vector	center;
	double		radius;
}				t_cylinder;

typedef struct	s_object
{
	t_cylinder	cyl;
	t_cone		cone;
	t_plane		plane;
	t_sphere	sphere;
	t_sphere	sphere2;
}				t_object;

typedef struct	s_tools
{
	int			x;
	int			y;
	double		t;
	double		p;
	double		c;
	double		s1;
	double		s2;
	double		cy;
}				t_tools;

typedef struct	s_base
{
	t_ray		ray;
	t_light		light;
}				t_base;

typedef struct	s_mlx
{
	int			bpp;
	int			s_l;
	void		*ptr;
	void		*img;
	int			*win;
	char		*str;
	int			endian;
}				t_mlx;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	dir;
	t_vector	vec;
}				t_camera;

typedef	struct	s_prim
{
	int		type;
	t_camera	camera;
	t_light		light;
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cyl;
	t_cone		cone;
	struct s_prim	*next;
}				t_prim;

typedef struct	s_all
{
	t_mlx		mlx;
	t_base		base;
	t_tools		tools;
	t_object	object;
	t_prim		prim;
}				t_all;

typedef enum	e_type
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	LIGHT
}				t_type;

void			fail(int i);
void			cone_ch(int fd);
void			light_ch(int fd);
void			plane_ch(int fd);
double			norm(t_vector v);
void			sphere_ch(int fd);
void			cylinder_ch(int fd);
t_vector		vec3_extract(int fd);
int				str_isdot(char *str);
t_color			color_extract(int fd);
t_vector		normalize(t_vector v);
int				str_isdigit(char *str);
int				check_vec3(char *line);
double			double_extract(int fd);
int				str_isdouble(char *str);
t_prim			*create_tab(int nb_obj);
int				key(int key, void *param);
double			dot(t_vector a, t_vector b);
int				lexer(char *file, int number);
t_vector		reflect(t_vector n, t_vector i);
double			power(double i, int power_value);
t_vector		getnormal_cone(t_vector inter_p);
void			smooth_rgb(t_color *color, int i);
int				name_obj(char *line, int *number);
t_prim			*init_parser(char *aled, int nb_obj);
void			cone_fill(int fd, t_prim *prim, int index);
void			plane_fill(int fd, t_prim *prim, int index);
void			light_fill(int fd, t_prim *prim, int index);
void			sphere_fill(int fd, t_prim *prim, int index);
//t_prim			*parser(char *file, int number, t_prim *prim);
t_prim			*parser(char *line, t_prim *prim);
void			cylinder_fill(int fd, t_prim *prim, int index);
t_prim			*cone_parsing(char *line, int *tab, t_prim *prim);
int				cone_intersect(t_cone cone, t_ray ray, double t);
t_prim			*light_parsing(char *line, int *tab, t_prim *prim);
t_prim			*plane_parsing(char *line, int *tab, t_prim *prim);
t_prim			*camera_parsing(char *line, int *tab, t_prim *prim);
t_prim			*sphere_parsing(char *line, int *tab, t_prim *prim);
int				plane_intersect(t_plane plane, t_ray ray, double t);
t_vector		getnormal_sphere(t_sphere sphere, t_vector inter_p);
t_prim			*cylinder_parsing(char *line, int *tab, t_prim *prim);
void			put_color(int x, int y, unsigned int *str, double dt);
int				sphere_intersect(t_sphere sphere, t_ray ray, double t);
int				cylinder_intersect(t_cylinder cyl, t_ray ray, double t);
void			geo_init(t_object *object, t_base *base, t_tools *tools);
void			draw_cone(t_base base, t_object object, t_mlx mlx, t_tools t);
int				cone_light_inter(t_cone cone, t_light light, t_vector inter_p);
int				sphere_light_inter(t_sphere sphere, t_light light, t_vector p);
void			draw_plane(t_base base, t_object object, t_mlx mlx, t_tools t);
void			cone_l_ext(t_cone c, t_vector p, t_light light, t_vector *vec);
t_vector		getnormal_cyl(t_cylinder cyl, t_vector p, t_ray ray, double t);
int				cylinder_light_inter(t_cylinder cyl, t_light light, t_vector p);
void			draw_sphere(t_base base, t_object object, t_mlx mlx, t_tools t);
void			draw_cyl(t_base base, t_object object, t_mlx mlx, t_tools tool);
#endif
