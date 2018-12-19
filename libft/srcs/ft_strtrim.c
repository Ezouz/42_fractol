/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:18:30 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 18:49:47 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	size_t			idx;

	if (!s)
		return (NULL);
	idx = 0;
	while ((s[idx] == ' ' || s[idx] == '\t' || s[idx] == '\n') && s[idx])
		idx++;
	if (!s[idx])
		return (ft_strsub(s, 0, 0));
	start = idx;
	idx = ft_strlen(s) - 1;
	while (s[idx] == ' ' || s[idx] == '\t' || s[idx] == '\n')
		idx--;
	len = idx - start + 1;
	return (ft_strsub(s, start, len));
}
