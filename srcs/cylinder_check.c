/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:22 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 12:52:22 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		cylinder_ch(int fd)
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
		if (str_isdigit(line) == 0)
			fail(1);
	if (ft_strcmp(line, "") == 0)
		fail(1);
	free(line);
	printf("cylinder OK\n");
}

void		cylinder_fill(int fd, t_prim *prim, int index)
{
	prim[index].cyl.center = vec3_extract(fd);
	prim[index].cyl.dir = vec3_extract(fd);
	prim[index].cyl.color = color_extract(fd);
	prim[index].cyl.radius = double_extract(fd);
}
