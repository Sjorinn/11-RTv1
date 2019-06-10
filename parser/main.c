/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:20:18 by pchambon          #+#    #+#             */
/*   Updated: 2019/06/10 15:48:54 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	main(int ac, char **av)
{
	t_prim *parser;

	if (ac != 2)
		return (0);
	parser = init_parser(av[1], 7);
	while (parser != NULL)
	{
		printf("type: %d\n", parser->type);
		parser = parser->next;
	}
	return (0);
}
