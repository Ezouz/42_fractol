/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:00:41 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 12:58:59 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		cu;
	unsigned char		*dest;
	const unsigned char *srce;

	cu = c;
	if (dst != NULL || src != NULL)
	{
		dest = (unsigned char*)dst;
		srce = (unsigned char *)src;
		while (n != 0)
		{
			*dest = *srce;
			if (*srce == cu)
			{
				return (dest + 1);
			}
			dest++;
			srce++;
			n--;
		}
	}
	return (NULL);
}
