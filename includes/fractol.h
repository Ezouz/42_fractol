/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:39:49 by ehouzard          #+#    #+#             */
/*   Updated: 2018/12/21 11:40:03 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <pthread.h>
# include "X.h"

# define WY 800
# define WX 1300
# define THREAD 8
# define BLANK 2W

typedef struct		s_event
{
	int				(*key)();
	int				(*mouse)();
	int				(*mouse_wheel)();
}					t_event;

typedef struct		s_cor
{
	double			x;
	double			y;
}					t_cor;

typedef	struct		s_param
{
	double			zoom;
	double			precision;
	int				clic;
	int				state;
	t_cor			ctr;
	t_cor			add;
	double			lum;
	double			color;
}					t_param;

typedef struct		s_thr
{
	pthread_t		thread;
	t_cor			pix;
	t_param			par;
	struct s_lib	*lib;
	struct s_thr	*next;
}					t_thr;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sz;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			i;
}					t_env;

typedef struct		s_lib
{
	t_env			env;
	t_event			event;
	t_thr			*thr;
	t_thr			*first;
	t_param			p;
}					t_lib;

void				ft_new_cor(t_cor *new, double x, double y);
void				ft_new_tsl(t_tsl *tsl, double t, double s, double l);

t_thr				*ft_new_thr(t_cor pix, t_lib *data);
void				ft_print_pixel(t_lib *data);
void				ft_create_thread(t_lib *data);
void				*ft_new_thread(void *add);

void				ft_parse_pixel(t_cor pix, t_param par, t_lib *data);
unsigned long		ft_convert_rvb(t_rvb clr);
void				ft_put_pixel(t_lib *data, int x, int y, int color);

void				init_event(char *fractal, t_lib *data);
void				init_hooks(t_lib *data);
void				load_state(t_lib *data);
int					to_window(t_lib *data);

int					keyboard_event(int keycode, t_lib *data);
void				key_param(int keycode, t_lib *data);
void				key_zoom(int keycode, double *zoom);
int					mouse_param(int z, int x, int y, t_lib *data);
int					param_julia(int x, int y, t_lib *data);

#endif
