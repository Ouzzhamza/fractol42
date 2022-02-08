/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:15:35 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 19:23:43 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ************************************************************************** */
/*                                                                            */
/*                             red_hook                                       */
/*                                                                            */
/* ************************************************************************** */

int	ft_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                             key_hook                                       */
/*                                                                            */
/* ************************************************************************** */

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_exit(data);
	else if (keycode == 123)
		data->x_center += 30 * data->x_scale;
	else if (keycode == 124)
		data->x_center -= 30 * data->x_scale;
	else if (keycode == 125)
		data->y_center -= 30 * data->y_scale;
	else if (keycode == 126)
		data->y_center += 30 * data->y_scale;
	else if (keycode == 69)
		data->it_max += 30;
	else if (keycode == 47 && data->color_change > 15.0)
			data->color_change -= 15.0;
	else if (keycode == 43 && data->color_change < 265.0)
			data->color_change += 15.50;
	else if (keycode == 15)
		fract_init(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                             mouse_move                                     */
/*                                                                            */
/* ************************************************************************** */

int	mouse_move(int x, int y, t_data *data)
{
	if (x > 0 && x < SIDE && y > 0 && y < SIDE && \
		(data->julia_p == 1) && data->fract == 1)
	{
		data->j_cr = (x * data->x_scale) - data->x_center;
		data->j_ci = (y * data->y_scale) - data->y_center;
	}
	if (x > 0 && x < SIDE && y > 0 && y < SIDE && \
		(data->julia_p == 1) && data->fract == 2)
	{
		data->jz3_cr = (x * data->x_scale) - data->x_center;
		data->jz3_ci = (y * data->y_scale) - data->y_center;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                             mouse_hook                                     */
/*                                                                            */
/* ************************************************************************** */

int	mouse_hook(int mouse, int x, int y, t_data *data)
{
	if (mouse == 5)
	{
		data->x_scale *= 0.5;
		data->y_scale *= 0.5;
		data->it_max += 20;
		data->x_center = data->x_center - (x * data->x_scale);
		data->y_center = data->y_center - (y * data->y_scale);
	}
	else if (mouse == 4 && data->it_max > 20)
	{
		data->x_center = data->x_center + (x * data->x_scale);
		data->y_center = data->y_center + (y * data->y_scale);
		data->x_scale /= 0.5;
		data->y_scale /= 0.5;
		data->it_max -= 20;
	}
	if (mouse == 1)
		data->julia_p *= -1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                             hundle_no_event                                */
/*                                                                            */
/* ************************************************************************** */

int	hundle_no_event(t_data *data)
{
	if (data->fract == 0)
		mandelbrot(data);
	if (data->fract == 1)
		julia(data);
	if (data->fract == 2)
		julia_z3(data);
	return (1);
}
