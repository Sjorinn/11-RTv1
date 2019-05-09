/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:07:19 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/09 15:13:32 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	geo_init(t_object *object, t_base *base, t_tools *tools, t_prim *prim)
{
//	************** FIRST SPHERE *******************
	object->sphere.center.x = WIDTH * 0.3;// creation d'un objet 'sphere'
	object->sphere.center.y = HEIGHT * 0.45;
	object->sphere.center.z = 1200;

	object->sphere.radius = 100;

	object->sphere.color.r = prim[0].sphere.color.r;// 			COULEUR
	object->sphere.color.g = prim[0].sphere.color.g;
	object->sphere.color.b = prim[0].sphere.color.b;

//	************** SECOND SPHERE *******************
	object->sphere2.center.x = WIDTH * 0.8;// creation d'un objet 'sphere'
	object->sphere2.center.y = HEIGHT * 0.7;
	object->sphere2.center.z = 100;

	object->sphere2.radius = 100;

	object->sphere2.color.r = 0;// 			COULEUR
	object->sphere2.color.g = 0x50;
	object->sphere2.color.b = 0xFF;

//	************** PLANE *******************
	object->plane.point.x = WIDTH / 2;//		POINT SUR LA PLAN
	object->plane.point.y = HEIGHT * 0.9;
	object->plane.point.z = 200;

	object->plane.normal.x = 0;//			NORMALE DU PLAN
	object->plane.normal.y = HEIGHT * 0.20;
	object->plane.normal.z = 100;
	object->plane.normal = normalize(object->plane.normal);

	object->plane.color.r = 0xB3;// 			COULEUR
	object->plane.color.g = 0xFF;
	object->plane.color.b = 0xFB;

//	************** CONE *******************
	object->cone.tip.x = WIDTH / 2;//			POSITION POINTE
	object->cone.tip.y = 200;
	object->cone.tip.z = 500;

	object->cone.b_center.x = WIDTH / 2;//		CENTRE BASE
	object->cone.b_center.y = HEIGHT - 200;
	object->cone.b_center.z = 500;

	object->cone.b_radius = 0.14;

	object->cone.color.r = 0xFF;// 			COULEUR
	object->cone.color.g = 0x20;
	object->cone.color.b = 0;

//	************** cyl *******************
	object->cyl.center.x = 100;//		CENTER BASE
	object->cyl.center.y = HEIGHT;
	object->cyl.center.z = 100;

	object->cyl.dir.x = 10;//			DIRECTION
	object->cyl.dir.y = 1;
	object->cyl.dir.z = 1;

	object->cyl.radius = 50;//			RADIUS BASE

	object->cyl.color.r = 0;//			COULEUR
	object->cyl.color.g = 0x50;
	object->cyl.color.b = 0x50;

//	************** LIGHT *******************
	base->light.src.x = WIDTH / 2;//			POSITION SOURCE
	base->light.src.y = 0;
	base->light.src.z = -1000;

	base->light.color.r = 0xFF;// 			COULEUR
	base->light.color.g = 0xFF;
	base->light.color.b = 0xFF;

//	************** RAY *******************
	base->ray.origin.x = 600;
	base->ray.origin.y = 600;
	base->ray.origin.z = -1500;

	base->ray.dir.x = 0;//la direction se place au tools 0/0 et look straight
	base->ray.dir.y = 0;
	base->ray.dir.z = 0;

	tools->y = -1;// y = -1 car incrementation && t= 20000 pour donner un max
}
