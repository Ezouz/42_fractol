/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:34:57 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/18 20:08:26 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thr		*ft_new_thr(t_cor pix, t_lib *data)
{
	t_thr	*thr;

	if (!(thr = (t_thr *)malloc(sizeof(t_thr))))
		return (NULL);
	thr->pix = pix;
	thr->par = data->p;
	thr->lib = data;
	thr->next = NULL;
	return (thr);
}

void		ft_new_tsl(t_tsl *tsl, double t, double s, double l)
{
	tsl->t = t;
	tsl->s = s;
	tsl->l = l;
}

void		ft_new_cor(t_cor *new, double x, double y)
{
	new->x = x;
	new->y = y;
}
