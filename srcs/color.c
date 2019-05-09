/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:05:15 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/09 15:05:39 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	reflect(t_vector nm, t_vector lr)
{
	t_vector	res;
	/*lr.x *= -1;
	lr.y *= -1;
	lr.z *= -1;*/

	res.x = 2.0 * dot(nm, lr) * nm.x - lr.x;
	res.y = 2.0 * dot(nm, lr) * nm.y - lr.y;
	res.z = 2.0 * dot(nm, lr) * nm.z - lr.z;
	return (res);
}

void	put_color(int x, int y, unsigned int *str, double dt)
{
		str[y * WIDTH + x] = 0x89D8F9 * dt;
}

double	power(double i, int power_value)
{
	double	tmp = i;
	while (power_value-- > 0)
		i *= tmp;
	return (i);
}
