/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:51:04 by ehouzard          #+#    #+#             */
/*   Updated: 2018/03/29 21:25:16 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isvalid(char c, int base)
{
	int		i;
	int		j;
	char	digits[17];
	char	digits2[17];

	i = -1;
	j = 0;
	while (++i < 16)
	{
		if (i < 10)
		{
			digits[i] = i + '0';
			digits2[i] = i + '0';
		}
		if (i > 9 && i < 16)
		{
			digits[i] = 'A' + j;
			digits2[i] = 'a' + j;
			j++;
		}
	}
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

static int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		result;
	int		sign;

	result = 0;
	while (ft_is_space(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}
