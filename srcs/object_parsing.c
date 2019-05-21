/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:51:58 by pchambon          #+#    #+#             */
/*   Updated: 2019/05/21 08:07:59 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		plane_parsing(char *line, int *tab, t_all *all)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "point: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "normale: ", 9) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 9, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "color: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[3] == 1)
		return (-1);
}

int		sphere_parsing(char *line, int *tab, t_all *all)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "center: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 2)
	{
		ft_strncmp(line, "radius: ", 8) == 0 ? : tab[3] == 1 ;
		all->object.sphere.radius = ft_atoi(line + 8);
	}
	if (tab[2] == 3)
	{
		ft_strncmp(line, "color: ", 7) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[3] == 1)
		return (-1);
}


int		cylinder_parsing(char *line, int *tab, t_all *all)
{
	int i;
	char **split;

	i = 0;
	tab[2] == 0 ? tab[2]++ : ;
	if (tab[2] == 1)
	{
		ft_strncmp(line, "center: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "direct: ", 8) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 8, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "radius: ", 9) == 0 ? : tab[3] == 1 ;
		all->object.cyl.radius = ft_atoi(line + 9) / 1000;
	}
	if (tab[2] == 1)
	{
		ft_strncmp(line, "couleur: ", 9) == 0 ? : tab[3] == 1 ;
		split = ft_strsplit(line + 7, ' ');
		while (split[i])
			;
		i != 3 ? tab[3] == 1 : ;
	}
	if (tab[3] == 1)
		return (-1);
}
