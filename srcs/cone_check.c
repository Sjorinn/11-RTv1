/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 16:29:52 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		cone_ch(int fd)
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

void		cone_fill(int fd, t_prim *prim, int index)
{
	prim[index].cone.tip = vec3_extract(fd);
	prim[index].cone.b_center = vec3_extract(fd);
	prim[index].cone.color = color_extract(fd);
	prim[index].cone.b_radius = double_extract(fd);
	prim[index].type = 2;
}
