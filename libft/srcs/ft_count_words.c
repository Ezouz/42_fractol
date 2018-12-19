/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:30:51 by ehouzard          #+#    #+#             */
/*   Updated: 2018/05/15 16:21:51 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (*s)
	{
		if (words == 0 && *s != c)
		{
			words++;
			i++;
		}
		else if (words == 1 && *s == c)
			words = 0;
		s++;
	}
	return (i);
}
