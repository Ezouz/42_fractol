/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:36:57 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 16:53:30 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = ft_count_words((char *)s, c);
	if (!(tab = (char **)malloc((sizeof(char *) * (nb_words + 1)))))
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_count_char((char *)s, c))))
			return (NULL);
		s = s + ft_count_char((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
