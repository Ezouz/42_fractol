/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:16:33 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/21 18:51:58 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t idx;
	size_t l_dst;
	size_t l_src;

	idx = 0;
	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	if (size == 0)
		return (l_src);
	while (size > l_dst + idx + 1 && src[idx])
	{
		dst[l_dst + idx] = src[idx];
		idx++;
	}
	dst[l_dst + idx] = '\0';
	if (size < l_dst)
		return (size + l_src);
	else
		return (l_dst + l_src);
}
