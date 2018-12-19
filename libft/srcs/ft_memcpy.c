/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:51:20 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 13:01:03 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*dest;
	unsigned char	*srce;

	idx = 0;
	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	while (idx < n)
	{
		dest[idx] = srce[idx];
		idx++;
	}
	return (dest);
}
