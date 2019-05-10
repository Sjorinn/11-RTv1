/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:26:54 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/10 15:29:14 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		plane_light_inter(t_plane plane, t_light light, double t)
{
	t_vector origin_center;

	origin_center.x = plane.point.x - light.src.x;
	origin_center.y = plane.point.y - light.src.y;
	origin_center.z = plane.point.z - light.src.z;
	t = -dot(origin_center, plane.normal) / dot(normalize(light.ray),\
		normalize(plane.normal));
	return (t);
}

int		plane_intersect(t_plane plane, t_ray ray, double t)
{
	t_vector	origin_center;
	double		d1;
	double		d2;

	origin_center.x = ray.origin.x - plane.point.x;
	origin_center.y = ray.origin.y - plane.point.y;
	origin_center.z = ray.origin.z - plane.point.z;
	if ((d1 = dot(ray.dir, plane.normal)) == 0)
		return (t);
	d2 = -dot(origin_center, plane.normal);
	t = d2 / d1;
	return (t);
}

void	plane_ext(t_vector *vec, double *tab, t_base base, t_tools tools)
{
	vec[0].x = base.ray.origin.x + base.ray.dir.x * tools.p;
	vec[0].y = base.ray.origin.y + base.ray.dir.y * tools.p;
	vec[0].z = base.ray.origin.z + base.ray.dir.z * tools.p;
	base.light.ray.x = vec[0].x - base.light.src.x;
	base.light.ray.y = vec[0].y - base.light.src.y;
	base.light.ray.z = vec[0].z - base.light.src.z;
	vec[2] = normalize(base.light.ray);
	vec[3] = normalize(base.ray.dir);
	vec[4].x = -vec[2].x + vec[3].x;
	vec[4].y = -vec[2].y + vec[3].y;
	vec[4].z = -vec[2].z + vec[3].z;
	vec[4] = normalize(vec[4]);
	tab[0] = dot(vec[3], vec[1]) * 0.5;
	tab[1] = dot(vec[2], vec[1]) * 2.5;
	tab[1] = tab[1] < 0 ? 0 : tab[1];
	tab[1] *= tab[1];
	tab[2] = dot(vec[1], vec[4]);
	tab[2] = tab[2] < 0 ? 0 : tab[2];
	tab[3] = 3 * power(tab[2], (double)100);
}

void	draw_plane(t_base base, t_object object, t_mlx mlx, t_tools tools)
{
	t_vector	vec[5];
	t_color		col[3];
	double		tab[4];

	vec[1] = object.plane.normal;
	col[0].r = object.plane.color.r * tab[1];
	col[0].g = object.plane.color.g * tab[1];
	col[0].b = object.plane.color.b * tab[1];
	col[1].r = base.light.color.r * tab[3];
	col[1].g = base.light.color.g * tab[3];
	col[1].b = base.light.color.b * tab[3];
	col[2].r = col[0].r + col[1].r + tab[0] * object.plane.color.r;
	col[2].g = col[0].g + col[1].g + tab[0] * object.plane.color.g;
	col[2].b = col[0].b + col[1].b + tab[0] * object.plane.color.b;
	smooth_rgb(col[2], 0);
	if (sphere_light_inter(object.sphere, base.light, vec[0]) == 1
		|| sphere_light_inter(object.sphere2, base.light, vec[0]) == 1
		|| cone_light_inter(object.cone, base.light, vec[0]) == 1
		|| cylinder_light_inter(object.cyl, base.light, vec[0]) == 1)
	{
		smooth_rgb(col[2], 1);
	}
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = col[2].b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = col[2].g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = col[2].r;
}
