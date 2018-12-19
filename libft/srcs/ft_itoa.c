/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:27:27 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/18 11:53:51 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenint(int n)
{
	int				cmp;
	unsigned int	nb;

	cmp = 0;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		cmp++;
	}
	if (nb == 0)
		cmp++;
	else
	{
		while (nb > 0)
		{
			cmp++;
			nb = nb / 10;
		}
	}
	return (cmp);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				idx;
	int				len;
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	if (!(str = malloc((sizeof(char) * lenint(n) + 1))))
		return (NULL);
	len = lenint(n);
	idx = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[idx] = nb % 10 + '0';
		nb = nb / 10;
		idx--;
	}
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}
