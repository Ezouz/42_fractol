/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:24:58 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/18 12:25:22 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;

	if (src >= dst)
	{
		tmp = (unsigned char *)dst;
		while (len--)
		{
			*tmp = *(unsigned char *)src;
			src++;
			tmp++;
		}
	}
	else
	{
		tmp = (unsigned char *)dst + len - 1;
		src = src + len - 1;
		while (len--)
		{
			*tmp = *(unsigned char *)src;
			src--;
			tmp--;
		}
	}
	return (dst);
}
