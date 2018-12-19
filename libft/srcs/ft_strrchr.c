/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:14:22 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 16:10:50 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	cu;
	char	*ptr;

	idx = ft_strlen(s);
	cu = c;
	if (ft_strlen(s) == 0 && c != 0)
		return (NULL);
	if (s[idx] == '\0' && c == 0)
	{
		ptr = (char*)&s[idx];
		return (ptr);
	}
	while (idx != 0 && s[idx] != cu)
		idx--;
	if (idx == 0 && s[idx] != cu)
		return (NULL);
	ptr = (char*)&s[idx];
	return (ptr);
}
