/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:51:58 by pchambon          #+#    #+#             */
/*   Updated: 2019/06/10 16:31:55 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_prim		*plane_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 3;
		ft_strncmp(line, "\t\tpoint: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->plane.point.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tnormale: ", 11) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 9, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->plane.normal.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "\t\tcolor: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->plane.color.tab[i - 1] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("plane\n");
	}
	tab[2] == 1 || tab[2] == 2 || tab[2] == 3 ? free(split): 0 ;
	return (prim);
}

t_prim		*sphere_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 4;
		ft_strncmp(line, "\t\tcenter: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split [2])
			return(NULL);
		while (++i < 4)
			prim->sphere.center.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tradius: ", 10) != 0 ? tab[3] = 1 : 0;
		if (tab[3] == 1)
			return(NULL);
		prim->sphere.radius = ft_atoi(line + 9);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "\t\tcolor: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->sphere.color.tab[i - 1] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("sphere\n");
	}
	tab[2] != 2 ? free(split) : 0;
	return (prim);
}

t_prim		*cylinder_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = -1;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 5;
		ft_strncmp(line, "\t\tcenter: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 8, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->cyl.center.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tdirect: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 8, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->cyl.dir.tab[i - 1] = ft_atoi(split[i]);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "\t\tradius: ", 10) != 0 ? tab[3] = 1 : 0;
		if (tab[3] == 1)
			return(NULL);
		prim->cyl.radius = ft_atoi(line + 10);
	}
	if (tab[2] == 4)
	{
		ft_strncmp(line, "\t\tcolor: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 7, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 4)
			prim->cyl.color.tab[i - 1] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("cylinder\n");
	}
	tab[2] != 3 ? free(split) : 0;
	return (prim);
}

t_prim		*cone_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = -1;
	tab[2]++;
	if (tab[2] == 1)
	{
		prim->type = 6;
		ft_strncmp(line, "\t\ttip: ", 7) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 6, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 3)
			prim->cone.tip.tab[i] = ft_atoi(split[i]);
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "\t\tcenter: ", 10) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 9, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 3)
			prim->cone.b_center.tab[i] = ft_atoi(split[i]);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "\t\tradius: ", 10) != 0 ? tab[3] = 1 : 0;
		if (tab[3] == 1)
			return(NULL);
		prim->cone.b_radius = ft_atoi(line + 10);
	}
	if (tab[2] == 4)
	{
		ft_strncmp(line, "\t\tcolor: ", 9) != 0 ? tab[3] = 1 : 0;
		split = ft_strsplit(line + 8, ' ');
		if (tab[3] == 1 || split[3] || !split[2])
			return(NULL);
		while (++i < 3)
			prim->cone.color.tab[i] = ft_atoi(split[i]);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[4]++;
		printf("cone\n");
	}
	tab[2] != 3 ? free(split) : 0;
	return (prim);
}
