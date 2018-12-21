/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:58 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/21 11:38:37 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_zoom(int keycode, double *zoom)
{
	if (keycode == 69 || keycode == 78)
	{
		if (*zoom * 0.7 > 0)
			*zoom *= (keycode == 78 ? 1.3 : 0.7);
	}
}

void	key_param(int keycode, t_lib *data)
{
	if (keycode == 83 || keycode == 86)
		data->p.precision += (keycode == 86) ? 2.0 : -2.0;
	else if (keycode == 84 || keycode == 87)
		data->p.lum += (keycode == 84 ? -1.0 : 1.0);
	else if (keycode == 85 || keycode == 88)
		data->p.color -= (keycode == 85 ? -1.0 : 1.0);
	else if (keycode == 123 || keycode == 124)
		data->p.ctr.x += (keycode == 123) ? -0.1 * data->p.zoom
											: 0.1 * data->p.zoom;
	else if (keycode == 125 || keycode == 126)
		data->p.ctr.y -= (keycode == 125) ? -0.1 * data->p.zoom
											: 0.1 * data->p.zoom;
	else if (keycode == 76)
		data->p.lum = 0.0;
	else if (keycode == 65)
		data->p.color = 0.0;
}

int		keyboard_event(int keycode, t_lib *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->env.mlx, data->env.i.img);
		mlx_destroy_window(data->env.mlx, data->env.win);
		free(data);
		exit(0);
	}
	else if (keycode == 49)
	{
		data->p.state += (data->p.state < 4) ? 1 : -4;
		load_state(data);
	}
	else if ((keycode >= 123 && keycode <= 126) ||
				(keycode == 65 || keycode == 76) ||
				(keycode >= 83 && keycode <= 88))
	{
		key_param(keycode, data);
	}
	else if (keycode == 69 || keycode == 78)
		key_zoom(keycode, &data->p.zoom);
	if (!to_window(data))
		return (1);
	return (0);
}
