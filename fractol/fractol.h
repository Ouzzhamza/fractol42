/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:25:37 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 19:13:28 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<stdio.h>
# include<stdlib.h>
# include<mlx.h>
# include<math.h>
# include<string.h>
# include<unistd.h>

# define SIDE 800

typedef struct s_data
{
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pexel;
	int		endian;
	int		fract;
	int		line_lenth;
	double	it;
	int		it_max;
	int		zoom;
	int		x;
	int		y;
	int		julia_p;
	double	color;
	double	x_scale;
	double	y_scale;
	double	x_center;
	double	y_center;
	double	im;
	double	re;
	double	j_cr;
	double	j_ci;
	double	jz3_cr;
	double	jz3_ci;	
	double	color_change;	
}	t_data;

int		main(int ac, char *av[]);
void	fract_init(t_data *data);
void	img_pix_put(t_data *img, int x, int y, int color);
void	pxl_to_img(t_data *img, int x, int y, int color);

/* ************************************************************************** */
/*                                                                            */
/*                             mandelbrot                                     */
/*                                                                            */
/* ************************************************************************** */

void	*mandelbrot(t_data *data);
void	mandelbrot_init(t_data *data);
void	mandelbrot_calc(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                                julia                                       */
/*                                                                            */
/* ************************************************************************** */

void	*julia(t_data *data);
void	julia_init(t_data *data);
void	julia_calc(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                             julia_z3_calc                                  */
/*                                                                            */
/* ************************************************************************** */

void	*julia_z3(t_data *data);
void	julia_z3_init(t_data *data);
void	julia_z3_calc(t_data *data);

void	img_pix_put(t_data *img, int x, int y, int color);
void	pxl_to_img(t_data *img, int x, int y, int color);

/* ************************************************************************** */
/*                                                                            */
/*                             hooks                                          */
/*                                                                            */
/* ************************************************************************** */

int		key_hook(int key, t_data *data);
int		ft_exit(t_data *data);
int		mouse_hook(int mouse, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
int		hundle_no_event(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                             coloring                                       */
/*                                                                            */
/* ************************************************************************** */

int		ft_color(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                             utiles                                         */
/*                                                                            */
/* ************************************************************************** */
int		ft_strcmp(const char *s1, const char *s2);

#endif
