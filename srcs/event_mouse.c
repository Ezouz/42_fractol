/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:31:27 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/18 20:18:53 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		param_julia(int x, int y, t_lib *data)
{
	int	mx;
	int	my;

	if ((data->p.state == 1 || data->p.state == 2
			|| data->p.state == 3) && data->p.clic != 1)
	{
		if (x < WX && x > 0 && y < WY && y > 0)
		{
			mx = x - WX / 2;
			my = WY / 2 - y;
			data->p.add.x +=
				(mx > 0) ? 0.001 * data->p.zoom : -0.001 * data->p.zoom;
			data->p.add.y -=
				(my > 0) ? 0.001 * data->p.zoom : -0.001 * data->p.zoom;
			if (!to_window(data))
				return (1);
		}
	}
	return (0);
}

int		mouse_param(int mouse_key, int x, int y, t_lib *data)
{
	if (mouse_key == 1)
		data->p.clic = (!data->p.clic) ? 1 : 0;
	else if (mouse_key == 2)
	{
		data->p.ctr.x += data->p.zoom * ((2 * (double)x / WX) - 1);
		data->p.ctr.y += data->p.zoom * ((2 * (double)y / WX) - 0.62);
	}
	else if (x < WX && x > 0 && y < WY && y > 0)
	{
		if (mouse_key == 5)
			key_zoom(69, &data->p.zoom);
		else if (mouse_key == 4)
			key_zoom(78, &data->p.zoom);
	}
	if (!to_window(data))
		return (1);
	return (0);
}
