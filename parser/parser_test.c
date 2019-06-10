/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:10:19 by pchambon          #+#    #+#             */
/*   Updated: 2019/06/10 15:51:59 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_prim		*object_parsing(char *line, int *tab, t_prim *prim)
{
	if (tab[1] == 1)
		return (plane_parsing(line, tab , prim));
	if (tab[1] == 2)
		return (sphere_parsing(line, tab , prim));
	if (tab[1] == 3)
		return (cylinder_parsing(line, tab , prim));
	if (tab[1] == 4)
		return (cone_parsing(line, tab , prim));
	if (ft_strcmp(line, "\ttype: plane") == 0)
		tab[1] = 1;
	if (ft_strcmp(line, "\ttype: sphere") == 0)
		tab[1] = 2;
	if (ft_strcmp(line, "\ttype: cylinder") == 0)
		tab[1] = 3;
	if (ft_strcmp(line, "\ttype: cone") == 0)
		tab[1] = 4;
	return (prim);
}

t_prim		*scene_parsing(char *line, int *tab, t_prim *prim)
{
	if (tab[1] == 1)
		return (camera_parsing(line, tab, prim));
	if(tab[1] == 2)
		return (light_parsing(line, tab, prim));
	if (ft_strcmp(line, "\tcamera:") == 0)
		tab[1] = 1;
	if (ft_strcmp(line, "\tlight:") == 0)
		tab[1] = 2;
	return (prim);
}

t_prim	*parser(char *line, t_prim *prim)
{
	static int tab[5];
	int			count;

	count = 0;
	while (count++ < tab[4])
		prim = prim->next;
	if (tab[0] == 1 && tab[1] != 0)
	{
		scene_parsing(line, tab, prim);
		return (prim);
	}
	if (tab[0] == 2 && tab[1] != 0)
	{
		object_parsing(line, tab, prim);
		return (prim);
	}
	if (tab[0] == 1 && tab[1] == 0)
	{
		if (ft_strcmp(line, "\tcamera:") == 0 || strcmp(line, "\tlight:") == 0)
			return(scene_parsing(line, tab, prim));
			else
				return (NULL);
	}
	if (tab[0] == 2 && tab[1] == 0)
	{
		if (ft_strcmp(line, "\ttype: plane") == 0 || \
			ft_strcmp(line, "\ttype: sphere") == 0 || \
			ft_strcmp(line, "\ttype: cylinder") == 0 || \
			ft_strcmp(line, "\ttype: cone") == 0)
				return(object_parsing(line, tab, prim));
		else
			return (NULL);
	}
	if (ft_strcmp(line, "scene:") == 0 && tab[0] == 0)
		tab[0] = 1;
	if (ft_strcmp(line, "object:") == 0 && tab[0] == 0)
		tab[0] = 2;
	else if (tab[0] == 0)
		return (NULL);
	return (prim);
}

t_prim	*init_parser(char *aled, int nb_obj)
{
	t_prim *prim;
	t_prim *head;
	char	*line;
	int		fd;
	int 	count;

	head = prim;
	count = 0;
	printf("%i\n", nb_obj);
	if (!(prim = (t_prim *)malloc(sizeof(t_prim) * 1)))
		return (NULL);
	head = prim;
	if ((fd = open(aled, O_RDONLY)) < 0)
		return (NULL);
	while (nb_obj-- != 0)
	{
		if (!(prim->next = (t_prim *)malloc(sizeof(t_prim))))
			return (NULL);
		nb_obj != 2 ? prim = prim->next : 0;
	}
	prim->next = NULL;
	prim = head;
	while (get_next_line(fd, &line) > 0)
		if (parser(line , prim) == NULL)
			return (null_str("parsing error.\n"));
	prim = head;
	while (prim != NULL)
	{
		if (prim->type == 2)
			count++;
		prim = prim->next;
	}
	if (count != 1)
		return (null_str("parsing error.\n"));
	return (head);
}
