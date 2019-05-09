/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:43:02 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 17:54:11 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			cylinder_intersect(t_cylinder cyl, t_ray ray, double t)
{
	t_vector	o_center;
	double		tab[6];

	o_center.x = ray.origin.x - cyl.center.x;
	o_center.y = ray.origin.y - cyl.center.y;
	o_center.z = ray.origin.z - cyl.center.z;
	tab[0] = dot(ray.dir, ray.dir) \
		- dot(ray.dir, cyl.dir) * dot(ray.dir, cyl.dir);
	tab[1] = 2 * (dot(ray.dir, o_center) - dot(ray.dir, cyl.dir)
	* dot(o_center, cyl.dir));
	tab[2] = dot(o_center, o_center) - dot(o_center, cyl.dir)
	* dot(o_center, cyl.dir) - cyl.radius * cyl.radius;
	tab[3] = tab[1] * tab[1] - 4.0 * tab[0] * tab[2];
	if (tab[3] < 0)
		return (t);
	else
	{
		tab[3] = sqrt(tab[3]);
		tab[5] = (-tab[1] + tab[3]) / (2 * tab[0]);
		tab[4] = (-tab[1] - tab[3]) / (2 * tab[0]);
		t = (tab[4] < 0) ? tab[5] : tab[4];
		return (t);
	}
}

t_vector	getnormal_cyl(t_cylinder cyl, t_vector inter_p, t_ray ray, double t)
{
	t_vector	normal;
	t_vector	o_center;
	double		m;

	o_center.x = ray.origin.x - cyl.center.x;
	o_center.y = ray.origin.y - cyl.center.y;
	o_center.z = ray.origin.z - cyl.center.z;
	m = dot(ray.dir, cyl.dir) * t + dot(o_center, cyl.dir);
	normal.x = inter_p.x - cyl.center.x - cyl.dir.x * m;
	normal.y = inter_p.y - cyl.center.y - cyl.dir.y * m;
	normal.z = inter_p.z - cyl.center.z - cyl.dir.z * m;
	return (normal);
}

void		draw_cyl(t_base base, t_object object, t_mlx mlx, t_tools tools)
{
	t_vector	vec[6];
	t_color		color[3];
	double		tab[5];

	vec[1].x = base.ray.origin.x + base.ray.dir.x * tools.cy;
	vec[1].y = base.ray.origin.y + base.ray.dir.y * tools.cy;
	vec[1].z = base.ray.origin.z + base.ray.dir.z * tools.cy;
	base.light.ray.x = base.light.src.x - vec[1].x;
	base.light.ray.y = base.light.src.y - vec[1].y;
	base.light.ray.z = base.light.src.z - vec[1].z;
	vec[2] = getnormal_cyl(object.cyl, vec[1], base.ray, tools.cy);
	vec[3] = normalize(vec[2]);
	vec[4] = normalize(base.light.ray);
	vec[5] = normalize(base.ray.dir);
	vec[0].x = -vec[4].x + vec[5].x;
	vec[0].y = -vec[4].y + vec[5].y;
	vec[0].z = -vec[4].z + vec[5].z;
	vec[0] = normalize(vec[0]);
	tab[1] = dot(vec[5], vec[3]) * 0.5;
	tab[2] = -dot(vec[3], vec[4]) * 2.5;
	tab[2] = tab[2] < 0 ? 0 : tab[2];
	tab[2] *= tab[2];
	color[1].r = object.cyl.color.r * tab[2];
	color[1].g = object.cyl.color.g * tab[2];
	color[1].b = object.cyl.color.b * tab[2];
	tab[3] = dot(vec[3], vec[0]);
	tab[3] = tab[3] < 0 ? 0 : tab[3];
	tab[4] = 3 * power(tab[3], (double)100);
	color[0].r = base.light.color.r * tab[4];
	color[0].g = base.light.color.g * tab[4];
	color[0].b = base.light.color.b * tab[4];
	color[2].r = color[1].r + color[0].r + tab[1] * object.sphere.color.r;
	color[2].g = color[1].g + color[0].g + tab[1] * object.sphere.color.g;
	color[2].b = color[1].b + color[0].b + tab[1] * object.sphere.color.b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = color[2].b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = color[2].g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = color[2].r;
}
