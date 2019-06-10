/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:10:19 by pchambon          #+#    #+#             */
/*   Updated: 2019/06/03 10:14:30 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		object_parsing(char *line, int *tab, t_prim *prim)
{
	if (tab[2] == 1)
		return (plane_parsing(line, tab , prim));
	if (tab[2] == 2)
		return (sphere_parsing(line, tab , prim));
	if (tab[2] == 3)
		return (cylinder_parsing(line, tab , prim));
	if (tab[2] == 4)
		return (cone_parsing(line, tab , prim));
	if (ft_strcmp(line, "\ttype: plane") == 0)
		tab[1] == 1;
	if (ft_strcmp(line, "\ttype: sphere") == 0)
		tab[1] == 2;
	if (ft_strcmp(line, "\ttype: cylinder") == 0)
		tab[1] == 3;
	if(ft_strcmp(line, "\ttype: cone"))
		tab[1] == 4;
	return (0);
}

int		scene_parsing(char *line, int *tab, t_prim *prim)
{
	if (tab[2] == 1)
		return (camera_parsing());
	if(tab[2] == 2)
		return (light_parsing());
	if (ft_strcmp(line, "\tcamera:")
		tab[2] == 1;
	if (ft_strcmp(line, "\tlight:"))
		tab[2] = 2;
	return (0);
}

t_prim	*parser(char *line, t_prim prim)
{
	static int tab[4];
	int ret;

	ret = 0;
	if (tab[0] == 1 && tab[3] != 0)
		scene_parsing();
	if (tab[0] == 2 && tab[3] != 0)
		object_parsing();
	if (line[0] != '\t')
		if (ft_strcmp(line, "scene:") != 0 && ft_strcmp(line, "object:") != 0)
			return (null_str("parsing error\n."));
	if (ft_strcmp(line, "scene:") == 0)
		tab[0] = 1;
	if (ft_strcmp(line, "object:") == 0)
		tab[0] = 2;
	if (tab[0] == 1 && tab[1] == 0)
	{
		if (ft_strcmp(line, "camera origin:") == 0 || strcmp(line, "light") == 0)
			scene_parsing(line, tab, all->prim);
			else
				return (null_str("parsing error\n."));
	}
	if (tab[0] == 2 && tab[1] == 0)
	{
		if (ft_strcmp(line, "\ttype: plane") == 0 || \
			ft_strcmp(line, "\ttype: sphere") == 0 || \
			ft_strcmp(line, "\ttype: cylinder") == 0 || \
			ft_strcmp(line, "\ttype: cone") == 0))
				object_parsing(line, tab, prim);
		else
			return (null_str("parsing error\n."));
	}
	if (ret = -1)
		return (null_str("parsing error\n."));
}

t_prim	*init_parser(char *aled, int nb_obj)
{
	t_prim *prim;
	t_prim *head;
	char	*line;

	head = prim;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (nb_obj != 0)
	{
		if (!(prim = (t_prim *)malloc(sizeof(t_prim) * 1)))
			return (NULL);
		prim = prim->next;
		nb_obj--;
	}
	prim->next = NULL;
	prim = head;
	while (get_next_line(aled, &line) > 0)
		parser(line , prim);
	return (head);
}
