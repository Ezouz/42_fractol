/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:44:43 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 17:04:25 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				idx;
	unsigned char	*p1;
	unsigned char	*p2;

	idx = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (p1[idx] && p2[idx])
	{
		if (p1[idx] == p2[idx])
			idx++;
		if (p1[idx] != p2[idx])
			return (p1[idx] - p2[idx]);
	}
	return ((p1[idx] - p2[idx]));
}
