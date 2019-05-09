/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:19:52 by pchambon          #+#    #+#             */
/*   Updated: 2019/01/02 16:19:25 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(((void *)new), 0, (size + 1));
	return (new);
}
