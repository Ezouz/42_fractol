/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_chartab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:26:48 by ehouzard          #+#    #+#             */
/*   Updated: 2018/01/15 17:30:02 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, int size_tab)
{
	int i;

	i = 0;
	while (i < size_tab)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}
