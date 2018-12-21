/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:17:37 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/18 20:08:51 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_carre(t_cor *pnt, t_param *par, t_tsl *tsl)
{
	t_cor		pnt1;

	pnt1.x = (pnt->x * pnt->x) - (pnt->y * pnt->y);
	pnt1.y = 2.0 * pnt->x * pnt->y;
	if (par->state == 4)
	{
		pnt1.x = (fabs(pnt->x * pnt->x) - (pnt->y * pnt->y)) - par->add.x;
		pnt1.y = -fabs(pnt1.y) - par->add.y;
	}
	else
	{
		pnt1.x += par->add.x;
		pnt1.y += par->add.y;
	}
	tsl->t += exp(-(sqrt(pnt->x * pnt->x + pnt->y * pnt->y)));
	*pnt = pnt1;
}

void			ft_parse_pixel(t_cor pix, t_param par, t_lib *data)
{
	t_tsl		tsl;
	t_cor		pnt;
	int			i;

	i = 0;
	pnt.x = par.ctr.x + ((2 * pix.x / WX) - 1) * par.zoom;
	pnt.y = par.ctr.y + ((2 * pix.y / WX) - 0.62) * par.zoom;
	if (par.state == 0 || par.state == 4)
		ft_new_cor(&par.add, pnt.x, pnt.y);
	ft_new_tsl(&tsl, exp(-(sqrt(pnt.x * pnt.x + pnt.y * pnt.y))), 1.0, 1.0);
	tsl.t += data->p.color;
	while (i++ <= data->p.precision && sqrt(pnt.x * pnt.x + pnt.y * pnt.y) < 4)
		ft_carre(&pnt, &par, &tsl);
	tsl.t /= data->p.precision;
	if (tsl.t >= 1.0)
		tsl.t -= 0.99;
	else if (tsl.t <= 0.0)
		tsl.t += 0.99;
	tsl.l += data->p.lum;
	ft_put_pixel(data, pix.x, pix.y, mlx_get_color_value(data->env.win,
					ft_convert_rvb(ft_tsl_to_rvb(tsl))));
}

void			*ft_new_thread(void *add)
{
	t_thr		*data;
	double		y;

	data = add;
	y = data->pix.y;
	while (data->pix.y < (y + 100.0))
	{
		while (data->pix.x <= WX)
		{
			ft_parse_pixel(data->pix, data->par, data->lib);
			data->pix.x++;
		}
		data->pix.x = 0;
		data->pix.y += 1.0;
	}
	pthread_exit(NULL);
}

void			ft_create_thread(t_lib *data)
{
	t_thr *tmp;

	while (data->thr)
		if (!(pthread_create(
						&data->thr->thread, NULL, ft_new_thread, data->thr)))
			data->thr = data->thr->next;
	data->thr = data->first;
	while (data->thr)
	{
		pthread_join(data->thr->thread, NULL);
		tmp = data->thr;
		data->thr = data->thr->next;
		free(tmp);
	}
}

void			ft_print_pixel(t_lib *data)
{
	t_cor		pix;

	data->thr = NULL;
	ft_new_cor(&pix, 0.0, 0.0);
	while (pix.y < WY)
	{
		if (!data->thr)
		{
			data->first = NULL;
			data->thr = ft_new_thr(pix, data);
			data->first = data->thr;
		}
		else
		{
			data->thr->next = ft_new_thr(pix, data);
			data->thr = data->thr->next;
		}
		pix.y += 100.0;
	}
	data->thr = data->first;
	ft_create_thread(data);
}
