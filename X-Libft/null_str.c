/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:24:31 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/13 12:03:24 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*null_str(const char *s)
{
	ft_putstr_fd(s, 1);
	return (NULL);
}
