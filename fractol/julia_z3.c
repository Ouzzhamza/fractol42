/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_z3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:30:29 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 19:32:32 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "fractol.h"

/* ************************************************************************** */
/*                                                                            */
/*                             julia_z3_set                                   */
/*                                                                            */
/* ************************************************************************** */

void	julia_z3_init(t_data *data)
{
	data->it_max = 50;
	data->x_scale = 4.0 / SIDE;
	data->y_scale = 4.0 / SIDE;
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->jz3_cr = 0.485000;
	data->jz3_ci = 0.555000;
	data->julia_p = 1;
	data->color_change = 265.0;
}

/* ************************************************************************** */
/*                                                                            */
/*                             julia_z3_calc                                  */
/*                                                                            */
/* ************************************************************************** */

void	julia_z3_calc(t_data *data)
{
	t_data	c;
	t_data	z;
	t_data	temp;

	c.re = data->jz3_ci;
	c.im = data->jz3_ci;
	data->it = 0;
	z.re = ((data->x * data->x_scale) - data->x_center);
	z.im = ((data->y * data->y_scale) - data->y_center);
	while ((z.re * z.re) + (z.im * z.im) < 4 && data->it < data->it_max)
	{
		temp.re = ((z.re * z.re * z.re) - (3 * z.re * z.im * z.im)) + c.re;
		temp.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im + c.im;
		z = temp;
		data->it++;
	}
	ft_color(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                             julia_z3                                       */
/*                                                                            */
/* ************************************************************************** */

void	*julia_z3(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->x < SIDE)
	{
		data->y = 0;
		while (data->y < SIDE)
		{
			julia_z3_calc(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
