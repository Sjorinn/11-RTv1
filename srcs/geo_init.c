/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:07:19 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/10 17:38:12 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	geo_init(t_object *object, t_base *base, t_tools *tools)
{
	object->sphere.center.x = WIDTH * 0.3;
	object->sphere.center.y = HEIGHT * 0.3;
	object->sphere.center.z = 1200;
	object->sphere.radius = 100;
	object->sphere.color.r = 0;
	object->sphere.color.g = 0xFF;
	object->sphere.color.b = 0;
	object->sphere2.center.x = WIDTH * 0.8;
	object->sphere2.center.y = HEIGHT * 0.7;
	object->sphere2.center.z = 100;
	object->sphere2.radius = 100;
	object->sphere2.color.r = 0;
	object->sphere2.color.g = 0x50;
	object->sphere2.color.b = 0xFF;
	object->plane.point.x = WIDTH / 2;
	object->plane.point.y = HEIGHT * 0.9;
	object->plane.point.z = 0;
	object->plane.normal.x = 0;
	object->plane.normal.y = HEIGHT * 0.20;
	object->plane.normal.z = 100;
	object->plane.normal = normalize(object->plane.normal);
	object->plane.color.r = 0;
	object->plane.color.g = 0xFF;
	object->plane.color.b = 0xFB;
	object->cone.tip.x = WIDTH * 0.1;
	object->cone.tip.y = 200;
	object->cone.tip.z = 500;
	object->cone.b_center.x = WIDTH * 0.1;
	object->cone.b_center.y = HEIGHT - 200;
	object->cone.b_center.z = 1000;
	object->cone.b_radius = 0.14;
	object->cone.color.r = 0xFF;
	object->cone.color.g = 0;
	object->cone.color.b = 0x10;
	object->cyl.center.x = 1000;
	object->cyl.center.y = 0;
	object->cyl.center.z = 1000;
	object->cyl.dir.x = 1;
	object->cyl.dir.y = -2;
	object->cyl.dir.z = 0;
	object->cyl.dir = normalize(object->cyl.dir);
	object->cyl.radius = 50;
	object->cyl.color.r = 0x100;
	object->cyl.color.g = 0x100;
	object->cyl.color.b = 0;
	base->light.src.x = WIDTH / 2;
	base->light.src.y = 0;
	base->light.src.z = -200;
	base->light.color.r = 0xFF;
	base->light.color.g = 0xFF;
	base->light.color.b = 0xFF;
	base->ray.origin.x = 600;
	base->ray.origin.y = 600;
	base->ray.origin.z = -1000;
	base->ray.dir.x = 0;
	base->ray.dir.y = 0;
	base->ray.dir.z = 0;
	tools->y = -1;
}
