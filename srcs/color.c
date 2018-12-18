/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:37:32 by ehouzard          #+#    #+#             */
/*   Updated: 2018/11/05 15:38:02 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_put_pixel(t_lib *data, int x, int y, int color)
{
	if (x > 0 && y > 0 && x < WX && y < WY &&
			data->env.i.sz * (WY + 0)
			> data->env.i.sz * y + (x * 4) + 3)
	{
		data->env.i.data[data->env.i.sz * y + (x * 4)] = color;
		data->env.i.data[data->env.i.sz * y + (x * 4) + 1] = color >> 8;
		data->env.i.data[data->env.i.sz * y + (x * 4) + 2] = color >> 16;
		data->env.i.data[data->env.i.sz * y + (x * 4) + 3] = 0;
	}
}

unsigned long	ft_convert_rvb(t_rvb clr)
{
	return ((((unsigned char)clr.r & 0xFF) << 16) +
			(((unsigned char)clr.v & 0xFF) << 8) +
			(((unsigned char)clr.b & 0xFF) << 0));
}
