/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:33:18 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 13:28:31 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t idx;
	size_t l_dest;

	idx = 0;
	l_dest = ft_strlen(s1);
	while (s2[idx])
		s1[l_dest++] = s2[idx++];
	s1[l_dest] = '\0';
	return (s1);
}
