/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:00:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/05/09 12:57:04 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		light_ch(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 2)
	{
		if (get_next_line(fd, &line) > 0)
			if (check_vec3(line) == 0)
				fail(1);
		if (ft_strcmp(line, "") == 0)
			fail(1);
		free(line);
	}
	printf("light OK\n");
}

void		light_fill(int fd, t_prim *prim, int index)
{
	prim[index].light.src = vec3_extract(fd);
	prim[index].light.color = color_extract(fd);
}
