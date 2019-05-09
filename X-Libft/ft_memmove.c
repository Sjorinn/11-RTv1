/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:42:29 by pchambon          #+#    #+#             */
/*   Updated: 2019/01/02 16:16:56 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptrd;
	char	*ptrs;

	ptrd = (char *)dst;
	ptrs = (char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	else
		while (n--)
		{
			ptrd[n] = ptrs[n];
		}
	return (dst);
}
