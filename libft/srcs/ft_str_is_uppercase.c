/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:49:23 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/22 10:56:22 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *str)
{
	int res;

	res = 1;
	while (*str)
	{
		if (str == 0)
			return (1);
		if ((*str >= 0 && *str < 65) || (*str > 90 && *str <= 127))
			res = 0;
		str++;
	}
	return (res);
}
