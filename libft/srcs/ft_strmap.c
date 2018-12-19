/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:08:48 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 18:20:34 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fs;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fs = malloc((sizeof(char) * ft_strlen(s)) + 1)))
		return (NULL);
	while (s[i])
	{
		fs[i] = f(s[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
