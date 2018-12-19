/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:56:10 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/14 10:53:33 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		r;
	char	rev;

	i = 0;
	r = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (i > r)
	{
		rev = str[i];
		str[i] = str[r];
		str[r] = rev;
		i--;
		r++;
	}
	return (str);
}
