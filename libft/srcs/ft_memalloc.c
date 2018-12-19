/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:11:55 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/17 18:06:19 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			cmp;
	void			*ptr;
	unsigned char	*ucptr;

	cmp = 0;
	if (!(ptr = (void*)malloc(sizeof(size_t) * size)))
		return (NULL);
	ucptr = ptr;
	while (cmp < size)
	{
		ucptr[cmp++] = 0;
	}
	return (ptr);
}
