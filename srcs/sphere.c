/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:33:16 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/10 15:35:28 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			sphere_light_inter(t_sphere sphere, t_light light, t_vector inter_p)
{
	t_vector	o_center;
	t_vector	lr;
	double		tab[7];

	o_center.x = inter_p.x - sphere.center.x;
	o_center.y = inter_p.y - sphere.center.y;
	o_center.z = inter_p.z - sphere.center.z;
	lr.x = light.src.x - inter_p.x;
	lr.y = light.src.y - inter_p.y;
	lr.z = light.src.z - inter_p.z;
	tab[0] = dot(lr, lr);
	tab[1] = 2 * dot(o_center, lr);
	tab[2] = dot(o_center, o_center) - sphere.radius * sphere.radius;
	tab[3] = tab[1] * tab[1] - 4.0 * tab[0] * tab[2];
	if (tab[3] < 0)
		return (0);
	tab[3] = sqrt(tab[3]);
	tab[4] = (-tab[1] + tab[3]) / (2 * tab[0]);
	tab[5] = (-tab[1] - tab[3]) / (2 * tab[0]);
	tab[6] = (tab[5] < 0) ? tab[4] : tab[5];
	if (tab[6] > 0)
		return (1);
	return (0);
}

int			sphere_intersect(t_sphere sphere, t_ray ray, double t)
{
	t_vector	o_center;
	double		tab[6];

	o_center.x = ray.origin.x - sphere.center.x;
	o_center.y = ray.origin.y - sphere.center.y;
	o_center.z = ray.origin.z - sphere.center.z;
	tab[0] = dot(ray.dir, ray.dir);
	tab[1] = 2 * dot(ray.dir, o_center);
	tab[2] = dot(o_center, o_center) - sphere.radius * sphere.radius;
	tab[3] = tab[1] * tab[1] - 4.0 * tab[0] * tab[2];
	if (tab[3] < 0)
		return (t);
	else
	{
		tab[3] = sqrt(tab[3]);
		tab[4] = (-tab[1] - tab[3]) / (2 * tab[0]);
		tab[5] = (-tab[1] + tab[3]) / (2 * tab[0]);
		t = (tab[4] < 0) ? tab[5] : tab[4];
		return (t);
	}
}

void		sphere_ext(double *tab, t_vector *vec, t_base base, t_object o)
{
	base.light.ray.x = base.light.src.x - vec[1].x;
	base.light.ray.y = base.light.src.y - vec[1].y;
	base.light.ray.z = base.light.src.z - vec[1].z;
	vec[2] = getnormal_sphere(o.sphere, vec[1]);
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
	tab[3] = dot(vec[3], vec[0]);
	tab[3] = tab[3] < 0 ? 0 : tab[3];
	tab[4] = 3 * power(tab[3], (double)100);
}

void		draw_sphere(t_base base, t_object object, t_mlx mlx, t_tools tools)
{
	t_vector	vec[6];
	t_color		color[3];
	double		tab[5];

	tab[0] = tools.s1 < tools.s2 ? tools.s1 : tools.s2;
	if (tab[0] == tools.s2)
		object.sphere = object.sphere2;
	vec[1].x = base.ray.origin.x + base.ray.dir.x * tab[0];
	vec[1].y = base.ray.origin.y + base.ray.dir.y * tab[0];
	vec[1].z = base.ray.origin.z + base.ray.dir.z * tab[0];
	color[1].r = object.sphere.color.r * tab[2];
	color[1].g = object.sphere.color.g * tab[2];
	color[1].b = object.sphere.color.b * tab[2];
	sphere_ext(tab, vec, base, object);
	color[0].r = base.light.color.r * tab[4];
	color[0].g = base.light.color.g * tab[4];
	color[0].b = base.light.color.b * tab[4];
	color[2].r = color[1].r + color[0].r + tab[1] * object.sphere.color.r;
	color[2].g = color[1].g + color[0].g + tab[1] * object.sphere.color.g;
	color[2].b = color[1].b + color[0].b + tab[1] * object.sphere.color.b;
	smooth_rgb(color[2], 0);
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = color[2].b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = color[2].g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = color[2].r;
}
