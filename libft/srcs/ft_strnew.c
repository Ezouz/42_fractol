/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:07:34 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 18:14:09 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	cmp;

	cmp = 0;
	if (!(str = (char*)malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (cmp < size)
		str[cmp++] = '\0';
	str[cmp] = '\0';
	return (str);
}
