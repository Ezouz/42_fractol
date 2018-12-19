/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:37:50 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/22 10:47:55 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(char *str)
{
	int res;

	res = 1;
	while (*str)
	{
		if (str == 0)
			return (1);
		if ((*str >= 0 && *str <= 96) || (*str >= 123 && *str <= 127))
			res = 0;
		str++;
	}
	return (res);
}
