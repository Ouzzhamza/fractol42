/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:34:12 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 20:41:12 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ************************************************************************** */
/*                                                                            */
/*                             fract_init                                     */
/*                                                                            */
/* ************************************************************************** */

void	fract_init(t_data *data)
{	
	if (data->fract == 0)
	{
		mandelbrot_init(data);
		mandelbrot(data);
	}
	else if (data->fract == 1)
	{
		julia_init(data);
		julia(data);
	}
	else if (data->fract == 2)
	{
		julia_z3_init(data);
		julia_z3(data);
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                             mlx_win_init                                   */
/*                                                                            */
/* ************************************************************************** */

void	mlx_win_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIDE, SIDE, "Fractol");
	data->img = mlx_new_image(data->mlx, SIDE, SIDE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pexel, \
		&data->line_lenth, &data->endian);
}

/* ************************************************************************** */
/*                                                                            */
/*                            coloring the pixel                              */
/*                                                                            */
/* ************************************************************************** */

void	pxl_to_img(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_lenth + x * (img->bits_per_pexel / 8));
	*(unsigned int *)pixel = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                             fract_comp                                     */
/*                                                                            */
/* ************************************************************************** */

int	fract_comp(char *av[], t_data *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(av[1], "julia_z3") == 0)
		data->fract = 2;
	else
	{
		printf("Usage /fractol \"mandelbrot\", \"julia\", \"julia_z3\"");
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                 main                                       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char *av[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (ac == 2)
	{
		mlx_win_init(data);
		if ((fract_comp(av, data)) == 0)
			return (0);
		fract_init(data);
		mlx_hook(data->win, 17, 0, ft_exit, data);
		mlx_hook(data->win, 2, 0, key_hook, data);
		mlx_hook(data->win, 6, 0, mouse_move, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop_hook(data->mlx, &hundle_no_event, data);
		mlx_loop(data->mlx);
	}
	else
		printf("Usage /fractol \"mandelbrot\", \"julia\", \"julia_z3\"");
	return (0);
}
