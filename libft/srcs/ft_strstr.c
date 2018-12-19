/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:38:58 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/22 11:31:56 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t idx;

	idx = 0;
	if (needle[idx] == '\0')
		return ((char*)haystack);
	while (haystack[idx] != '\0')
	{
		if (ft_strnequ((haystack + idx), needle, ft_strlen(needle)) == 1)
			return ((char*)(haystack + idx));
		idx++;
	}
	return (NULL);
}
