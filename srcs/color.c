/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:05:15 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/10 15:26:21 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	reflect(t_vector nm, t_vector lr)
{
	t_vector	res;

	res.x = 2.0 * dot(nm, lr) * nm.x - lr.x;
	res.y = 2.0 * dot(nm, lr) * nm.y - lr.y;
	res.z = 2.0 * dot(nm, lr) * nm.z - lr.z;
	return (res);
}

void		put_color(int x, int y, unsigned int *str, double dt)
{
	str[y * WIDTH + x] = 0x89D8F9 * dt;
}

double		power(double i, int power_value)
{
	double	tmp;

	tmp = i;
	while (power_value-- > 0)
		i *= tmp;
	return (i);
}

void		smooth_rgb(t_color color, int i)
{
	if (i == 0)
	{
		color.r = (color.r / 255.0) / ((color.r / 255.0) + 1) * 255.0;
		color.g = (color.g / 255.0) / ((color.g / 255.0) + 1) * 255.0;
		color.b = (color.b / 255.0) / ((color.b / 255.0) + 1) * 255.0;
	}
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
}
