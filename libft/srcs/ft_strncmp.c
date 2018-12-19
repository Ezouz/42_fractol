/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:10:11 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 17:19:26 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*p1;
	unsigned char	*p2;

	idx = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (p1[idx] && p2[idx] && idx < n - 1)
	{
		if (p1[idx] != p2[idx])
			return (p1[idx] - p2[idx]);
		if (p1[idx] == p2[idx])
			idx++;
	}
	if (p1[idx] == p2[idx])
		return (0);
	return (p1[idx] - p2[idx]);
}
