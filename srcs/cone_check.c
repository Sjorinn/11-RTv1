/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/10 16:06:27 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	cone_ch(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 3)
	{
		if (get_next_line(fd, &line) > 0)
			if (check_vec3(line) == 0)
				fail(1);
		if (ft_strcmp(line, "") == 0)
			fail(1);
		free(line);
	}
	if (get_next_line(fd, &line) > 0)
		if (str_isdouble(line) == 0)
			fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
	printf("cone OK\n");
}

void	cone_fill(int fd, t_prim *prim, int index)
{
	prim[index].cone.tip = vec3_extract(fd);
	prim[index].cone.b_center = vec3_extract(fd);
	prim[index].cone.color = color_extract(fd);
	prim[index].cone.b_radius = double_extract(fd);
	prim[index].type = 2;
}

void	cone_l_ext(t_cone cone, t_vector inter_p, t_light light, t_vector *vec)
{
	vec[0].x = inter_p.x - cone.tip.x;
	vec[0].y = inter_p.y - cone.tip.y;
	vec[0].z = inter_p.z - cone.tip.z;
	vec[2].x = light.src.x - inter_p.x;
	vec[2].y = light.src.y - inter_p.y;
	vec[2].z = light.src.z - inter_p.z;
	vec[1].x = cone.b_center.x - cone.tip.x;
	vec[1].y = cone.b_center.y - cone.tip.y;
	vec[1].z = cone.b_center.z - cone.tip.z;
}
