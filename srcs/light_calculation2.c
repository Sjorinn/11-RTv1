/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calculation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:27:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/09/04 15:29:42 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		cap(t_color color)
{
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	color.r = color.r < 0 ? 0 : color.r;
	color.g = color.g < 0 ? 0 : color.g;
	color.b = color.b < 0 ? 0 : color.b;
	return (color);
}

t_color		multi_l_co(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	final = rgb_value(color, 0, 0, 0);
	i.j = -1;
	v[1] = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	v[3] = getnm_co(v[1], prim[base.tools.i].cone, base.ray, base.tools.t);
	v[0] = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			v[2] = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), v[0]));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, v[1]));
			l_e.a = ambient_l(v[0], v[3], -0.5);
			l_e.d = diffuse_l(v[3], prim[i.j].light.ray, color);
			l_e.s = specular_l(v[3], v[2], prim[i.j].light.color, -1.0);
			if (shadow(prim, i, base, v[1]) == 0)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
		}
	}
	return (cap(final));
}

t_color		multi_l_cy(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	final = rgb_value(color, 0, 0, 0);
	i.j = -1;
	v[1] = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	v[3] = nrmz(gtnm_cyl(prim[base.tools.i].cyl, v[1], base.ray, base.tools.t));
	v[0] = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			v[2] = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), v[0]));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, v[1]));
			l_e.a = ambient_l(v[0], v[3], -0.5);
			l_e.d = diffuse_l(v[3], prim[i.j].light.ray, color);
			l_e.s = specular_l(v[3], v[2], prim[i.j].light.color, -1.0);
			if (shadow(prim, i, base, v[1]) == 0)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
		}
	}
	return (cap(final));
}

t_color		multi_l_s(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[4];
	t_l_eff		l_e;
	t_color		final;

	final = rgb_value(color, 0, 0, 0);
	v[1] = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	v[3] = getnormal_sphere(prim[base.tools.i].sphere, v[1]);
	v[0] = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			v[2] = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), v[0]));
			prim[i.j].light.ray = nrmz(vec_sub(prim[i.j].light.src, v[1]));
			l_e.a = ambient_l(v[0], v[3], 0.5);
			l_e.d = diffuse_l(v[3], prim[i.j].light.ray, color);
			l_e.s = specular_l(v[3], v[2], prim[i.j].light.color, 1.0);
			if (shadow(prim, i, base, v[1]) == 0)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
		}
	}
	return (cap(final));
}

t_color		multi_l_p(t_prim *prim, t_base base, t_color color, t_i i)
{
	t_vector	v[3];
	t_l_eff		l_e;
	t_color		final;

	final = rgb_value(color, 0, 0, 0);
	i.j = -1;
	v[1] = vec_add(base.ray.origin, vec_mult_d(base.ray.dir, base.tools.t));
	v[0] = nrmz(base.ray.dir);
	while (++i.j < i.nb)
	{
		if (prim[i.j].type == LIGHT)
		{
			v[2] = nrmz(vec_add(vec_mult_d(prim[i.j].light.ray, -1), v[0]));
			prim[i.j].light.ray = nrmz(vec_sub(v[1], prim[i.j].light.src));
			l_e.a = ambient_l(v[0], prim[base.tools.i].plane.normal, 0.5);
			l_e.d = diffuse_l_alt(prim[base.tools.i].plane.normal,
			prim[i.j].light.ray, color);
			l_e.s = rgb_value(color, 0, 0, 0);
			if (shadow(prim, i, base, v[1]) == 0)
				final = color_add(final, l_effect(l_e.d, l_e.s, l_e.a, color));
		}
	}
	return (cap(final));
}
