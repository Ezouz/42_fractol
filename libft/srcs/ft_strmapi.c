/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:44:20 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 18:21:23 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fs;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fs = malloc((sizeof(char) * ft_strlen(s)) + 1)))
		return (NULL);
	while (s[i])
	{
		fs[i] = f(i, s[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
