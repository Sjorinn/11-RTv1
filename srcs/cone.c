/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:08:43 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/10 17:05:34 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			cone_light_inter(t_cone cone, t_light light, t_vector inter_p)
{
	t_vector	vec[4];
	double		tab[9];

	cone_l_ext(cone, inter_p, light, vec);
	tab[0] = norm(vec[1]);
	vec[3].x = vec[1].x / tab[0];
	vec[3].y = vec[1].y / tab[0];
	vec[3].z = vec[1].z / tab[0];
	tab[1] = cone.b_radius * cone.b_radius / tab[0] * tab[0];
	tab[2] = dot(vec[2], vec[2]) - tab[1] * dot(vec[2], vec[3])
		* dot(vec[2], vec[3]) - dot(vec[2], vec[3]) * dot(vec[2], vec[3]);
	tab[3] = 2 * (dot(vec[2], vec[0]) - tab[1] * dot(vec[2], vec[3])
		* dot(vec[0], vec[3]) - dot(vec[2], vec[3]) * dot(vec[0], vec[3]));
	tab[4] = dot(vec[0], vec[0]) - tab[1] * dot(vec[0], vec[3])
		* dot(vec[0], vec[3]) - dot(vec[0], vec[3]) * dot(vec[0], vec[3]);
	tab[5] = tab[3] * tab[3] - 4.0 * tab[2] * tab[4];
	if (tab[5] < 0)
		return (0);
	tab[5] = sqrt(tab[5]);
	tab[7] = (-tab[3] + tab[5]) / (2 * tab[2]);
	tab[6] = (-tab[3] - tab[5]) / (2 * tab[2]);
	tab[8] = (tab[6] < 0) ? tab[7] : tab[6];
	if (tab[8] > 0)
		return (1);
	return (0);
}

void		cone_int_ext(t_vector *vec, double *tab, t_cone cone, t_ray ray)
{
	vec[0].x = ray.origin.x - cone.tip.x;
	vec[0].y = ray.origin.y - cone.tip.y;
	vec[0].z = ray.origin.z - cone.tip.z;
	vec[1].x = cone.b_center.x - cone.tip.x;
	vec[1].y = cone.b_center.y - cone.tip.y;
	vec[1].z = cone.b_center.z - cone.tip.z;
	tab[0] = norm(vec[1]);
	vec[2].x = vec[1].x / tab[0];
	vec[2].y = vec[1].y / tab[0];
	vec[2].z = vec[1].z / tab[0];
}

int			cone_intersect(t_cone cone, t_ray ray, double t)
{
	t_vector	vec[3];
	double		tab[8];

	cone_int_ext(vec, tab, cone, ray);
	tab[1] = cone.b_radius * cone.b_radius / tab[0] * tab[0];
	tab[2] = dot(ray.dir, ray.dir) - tab[1] * dot(ray.dir, vec[2])
		* dot(ray.dir, vec[2]) - dot(ray.dir, vec[2]) * dot(ray.dir, vec[2]);
	tab[3] = 2 * (dot(ray.dir, vec[0]) - tab[1] * dot(ray.dir, vec[2])
		* dot(vec[0], vec[2]) - dot(ray.dir, vec[2]) * dot(vec[0], vec[2]));
	tab[4] = dot(vec[0], vec[0]) - tab[1] * dot(vec[0], vec[2]) \
		* dot(vec[0], vec[2]) - dot(vec[0], vec[2]) * dot(vec[0], vec[2]);
	tab[5] = tab[3] * tab[3] - 4.0 * tab[2] * tab[4];
	if (tab[5] < 0)
		return (t);
	else
	{
		tab[5] = sqrt(tab[5]);
		tab[7] = (-tab[3] + tab[5]) / (2 * tab[2]);
		tab[6] = (-tab[3] - tab[5]) / (2 * tab[2]);
		t = (tab[6] < 0) ? tab[7] : tab[6];
		return (t);
	}
}

void		cone_ext(double *tab, t_vector *vec, t_base base)
{
	base.light.ray.x = base.light.src.x - vec[1].x;
	base.light.ray.y = base.light.src.y - vec[1].y;
	base.light.ray.z = base.light.src.z - vec[1].z;
	vec[2] = getnormal_cone(vec[1]);
	vec[3] = normalize(vec[2]);
	vec[4] = normalize(base.light.ray);
	vec[5] = normalize(base.ray.dir);
	vec[0].x = -vec[4].x + vec[5].x;
	vec[0].y = -vec[4].y + vec[5].y;
	vec[0].z = -vec[4].z + vec[5].z;
	vec[0] = normalize(vec[0]);
	tab[1] = -dot(vec[5], vec[3]) * 0.5;
	tab[2] = dot(vec[3], vec[4]) * 2.5;
	tab[2] = tab[2] < 0 ? 0 : tab[2];
	tab[2] *= tab[2];
	tab[3] = -dot(vec[3], vec[0]);
	tab[3] = tab[3] < 0 ? 0 : tab[3];
	tab[4] = 3 * power(tab[3], (double)100);
}

void		draw_cone(t_base base, t_object object, t_mlx mlx, t_tools tools)
{
	t_vector	vec[6];
	t_color		color[3];
	double		tab[5];

	vec[1].x = base.ray.origin.x + base.ray.dir.x * tools.c;
	vec[1].y = base.ray.origin.y + base.ray.dir.y * tools.c;
	vec[1].z = base.ray.origin.z + base.ray.dir.z * tools.c;
	cone_ext(tab, vec, base);
	color[1].r = object.cone.color.r * tab[2];
	color[1].g = object.cone.color.g * tab[2];
	color[1].b = object.cone.color.b * tab[2];
	color[0].r = base.light.color.r * tab[4];
	color[0].g = base.light.color.g * tab[4];
	color[0].b = base.light.color.b * tab[4];
	color[2].r = color[1].r + color[0].r + tab[1] * object.cone.color.r;
	color[2].g = color[1].g + color[0].g + tab[1] * object.cone.color.g;
	color[2].b = color[1].b + color[0].b + tab[1] * object.cone.color.b;
	smooth_rgb(&color[2], 0);
	mlx.str[(tools.y * WIDTH + tools.x) * 4] = color[2].b;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 1] = color[2].g;
	mlx.str[(tools.y * WIDTH + tools.x) * 4 + 2] = color[2].r;
}
