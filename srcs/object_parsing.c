/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:51:58 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/31 16:59:14 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		plane_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "point: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (++i < 3)
			prim->plane.point.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "normale: ", 9) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 9, ' ');
		while (++i < 3)
			prim->plane.normal.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "color: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (++i < 3)
			prim->plane.color.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	free(split);
	if (tab[3] == 1)
		return (-1);
	return (0);
}

int		sphere_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "center: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (++i < 3)
			prim->sphere.center.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "radius: ", 8) == 0 ? : tab[3] == 1 ;
		prim->sphere.radius = ft_atoi(line + 8);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "color: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (++i < 3)
			prim->sphere.color.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	free(split);
	if (tab[3] == 1)
		return (-1);
	return (0);
}


int		cylinder_parsing(char *line, int *tab, t_prim *prim)
{
	int i;
	char **split;

	i = -1;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "center: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (++i < 3)
			prim->cyl.center.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "direct: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (++i < 3)
			prim->cyl.dir.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "radius: ", 9) == 0 ? : tab[3] == 1 ;
		all->object.cyl.radius = ft_atoi(line + 9) / 1000;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "color: ", 9) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (++i < 3)
			prim->cyl.color.tab[i] = ft_atoi(split[i]);
		i != 3 ? tab[3] == 1 : ;
	}
	free(split);
	if (tab[3] == 1)
		return (-1);
	return (0);
}
