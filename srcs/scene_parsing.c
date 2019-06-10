/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:29:34 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/31 15:22:48 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		camera_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "origin: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	free(split);
	if (tab[3] == 1)
		return (-1);
	return (0);
}

int		light_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = -1;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "origin: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (++i < 3)
			prim->light.src.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "color: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (i++ < 3)
			prim->light.color.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	free(split);
	if (tab[3] == 1)
		return (-1);
	return (0);
}
