/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:25:38 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/18 20:06:24 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_event(char *fractal, t_lib *data)
{
	if (ft_strcmp(fractal, " "))
	{
		if (!ft_strcmp(fractal, "burningship"))
			data->p.state = 4;
		else if (!ft_strcmp(fractal, "julia"))
			data->p.state = 1;
		else if (!ft_strcmp(fractal, "mandelbrot"))
			data->p.state = 0;
		else
		{
			ft_putstr("usage: ./fractol [julia][mandelbrot][burningship]\n");
			mlx_destroy_image(data->env.mlx, data->env.i.img);
			mlx_destroy_window(data->env.mlx, data->env.win);
			free(data);
			exit(1);
		}
	}
	load_state(data);
}

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
	data->p.zoom = 2.0;
	data->p.color = 0.0;
	data->p.lum = 0.0;
	ft_new_cor(&data->p.ctr, 0.0, 0.0);
}

void	init_hooks(t_lib *data)
{
	data->event.key = &keyboard_event;
	mlx_hook(data->env.win, KeyPress, KeyRelease, data->event.key, data);
	data->event.mouse = &param_julia;
	mlx_hook(data->env.win, MotionNotify, PointerMotionMask, param_julia, data);
	data->event.mouse_wheel = &mouse_param;
	mlx_hook(data->env.win, Button4, ButtonPressMask, mouse_param, data);
}

int		to_window(t_lib *data)
{
	mlx_clear_window(data->env.mlx, data->env.win);
	ft_print_pixel(data);
	return (mlx_put_image_to_window(data->env.mlx, data->env.win,
									data->env.i.img, 0, 0));
}
