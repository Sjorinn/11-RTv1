/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:29:34 by pchambon          #+#    #+#             */
/*   Updated: 2019/06/10 16:32:19 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_prim		*camera_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 2;
		ft_strncmp(line, "\t\torigin: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 8, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->camera.origin.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tdir: ", 7) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 5, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->camera.dir.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "\t\tvec: ", 7) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 5, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->camera.vec.tab[i - 1] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("camera\n");
	}
	tab[2] == 1 || tab[2] == 2 || tab[2] == 3 ? free(split): 0 ;
	return (prim);
}

t_prim		*light_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 1;
		ft_strncmp(line, "\t\torigin: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 8, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->light.src.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tcolor: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		printf("%i\n", tab[3]);
		while (++i < 4)
			prim->light.color.tab[i - 1] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("light\n");
	}
	tab[2] == 1 || tab[2] == 2 ? free(split): 0 ;
	return (prim);
}
