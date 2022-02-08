/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:03:01 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 20:04:22 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "fractol.h"

/* ************************************************************************** */
/*                                                                            */
/*                             mandelbrot_set                                 */
/*                                                                            */
/* ************************************************************************** */

void	mandelbrot_init(t_data *data)
{
	data->it_max = 50;
	data->x_scale = 4.0 / SIDE;
	data->y_scale = 4.0 / SIDE;
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->color_change = 265.0;
}

/* ************************************************************************** */
/*                                                                            */
/*                             mandelbrot_calc                                */
/*                                                                            */
/* ************************************************************************** */

void	mandelbrot_calc(t_data *data)
{
	t_data	c;
	t_data	z;
	t_data	temp;

	c.re = ((data->x * data->x_scale) - data->x_center);
	c.im = ((data->y * data->y_scale) - data->y_center);
	data->it = 0.0;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re) + (z.im * z.im) < 4 && data->it < data->it_max)
	{
		temp.re = ((z.re * z.re) - (z.im * z.im)) + c.re;
		temp.im = 2 * z.re * z.im + c.im;
		z = temp;
		data->it++;
	}
	ft_color(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                             mandelbrot                                     */
/*                                                                            */
/* ************************************************************************** */
void	*mandelbrot(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->x < SIDE)
	{
		data->y = 0;
		while (data->y < SIDE)
		{
			mandelbrot_calc(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
