/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:01:15 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/10 15:02:14 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	getnormal_sphere(t_sphere sphere, t_vector inter_p)
{
	t_vector	normal;

	normal.x = (sphere.center.x - inter_p.x);
	normal.y = (sphere.center.y - inter_p.y);
	normal.z = (sphere.center.z - inter_p.z);
	return (normal);
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

t_vector	getnormal_cone(t_vector inter_p)
{
	t_vector	normal;

	inter_p.y *= -1;
	normal = normalize(inter_p);
	return (normal);
}
