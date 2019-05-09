/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:59:41 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 12:53:06 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		plane_ch(int fd)
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
	printf("plane OK\n");
}

void		plane_fill(int fd, t_prim *prim, int index)
{
	prim[index].plane.point = vec3_extract(fd);
	prim[index].plane.normal = vec3_extract(fd);
	prim[index].plane.color = color_extract(fd);
}
