/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:48:26 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 13:51:13 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t idx;
	size_t l_dest;

	idx = 0;
	l_dest = ft_strlen(s1);
	while (idx < n && s2[idx])
	{
		s1[l_dest] = s2[idx];
		l_dest++;
		idx++;
	}
	s1[l_dest] = '\0';
	return (s1);
}
