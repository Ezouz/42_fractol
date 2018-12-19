/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:19:26 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 14:07:12 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			idx;
	unsigned char	cu;
	char			*ptr;

	idx = 0;
	cu = c;
	while (s[idx] != '\0' && s[idx] != cu)
		idx++;
	if (s[idx] == 0 && cu != 0)
		return (NULL);
	ptr = (char*)&s[idx];
	return (ptr);
}
