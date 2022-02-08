/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:01:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/01/20 19:10:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(t_data *data)
{
	int	pixel;

	data->color = data->it / 8 - log (1);
	pixel = (data->x + data->y * SIDE) * 4;
	if (data->it == data->it_max)
	{
		data->addr[pixel + 0] = 0;
		data->addr[pixel + 1] = 0;
		data->addr[pixel + 2] = 0;
	}
	else
	{
		data->addr[pixel + 0] = sin(0.04 * data->color + 1) * 400;
		data->addr[pixel + 1] = sin(0.01 * data->color + 1) * 400;
		data->addr[pixel + 2] = data->color_change;
	}
	return (0);
}
