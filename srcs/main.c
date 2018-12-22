/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:51:32 by ehouzard          #+#    #+#             */
/*   Updated: 2018/11/05 15:10:10 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fractol(t_lib *data, char **av)
{
	data->env.mlx = mlx_init();
	data->env.win = mlx_new_window(data->env.mlx, WX, WY, "fractol");
	data->env.i.img = mlx_new_image(data->env.mlx, WX, WY);
	data->env.i.data = mlx_get_data_addr(data->env.i.img,
				&data->env.i.bpp, &data->env.i.sz, &data->env.i.endian);
	init_event(av[1], data);
	init_hooks(data);
	if (!to_window(data))
		return (1);
	mlx_loop(data->env.mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_lib	data;

	if (ac != 2)
	{
		ft_putstr("usage: ./fractol [julia][mandelbrot][burningship]\n");
		return (1);
	}
	if (check_arg(av[1]))
		return (1);
	return (fractol(&data, av));
}
