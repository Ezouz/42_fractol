/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:28:58 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/18 20:04:57 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	load_state(t_lib *data)
{
	if (data->p.state == 1)
		ft_new_cor(&data->p.add, 0.285, 0.01);
	else if (data->p.state == 2)
		ft_new_cor(&data->p.add, -0.123, 0.745);
	else if (data->p.state == 3)
		ft_new_cor(&data->p.add, -0.038088, 0.97);
	else
		ft_new_cor(&data->p.add, 0.0, 0.0);
	data->p.precision = 45.0;
	data->p.zoom = 2;
	ft_new_cor(&data->p.ctr, 0.0, 0.0);
}

void	key_move(int keycode, double *x, double *y, double zoom)
{
	if (keycode == 123 || keycode == 124)
		*x += (keycode == 123 ? -0.1 * zoom : 0.1 * zoom);
	else if (keycode == 125 || keycode == 126)
		*y -= (keycode == 125 ? -0.1 * zoom : 0.1 * zoom);
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
	else if (keycode >= 123 && keycode <= 126)
		key_move(keycode, &data->p.ctr.x, &data->p.ctr.y, data->p.zoom);
	else if (keycode == 78)
		key_zoom(78, &data->p.zoom);
	else if (keycode == 69)
		key_zoom(69, &data->p.zoom);
	else if (keycode == 82 || keycode == 83)
		key_precision(keycode, &data->p.precision);
	if (!to_window(data))
		return (1);
	return (0);
}
