/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:32:16 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/21 17:21:49 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t midx;
	size_t i;
	size_t j;
	size_t nlen;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	nlen = ft_strlen(needle);
	j = 0;
	while (haystack[i] && i < len)
	{
		midx = i;
		while (needle[j] == haystack[i + j] && midx < len)
		{
			if (j == nlen - 1)
				return ((char*)haystack + i);
			j++;
			midx++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
