/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:15:47 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/14 16:46:14 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float ft_abs(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	isometric(float *x, float *y, int z, t_game *game)
{
	*x = (*x - *y) * cos(game->angle);
	*y = (*x + *y) * sin(game->angle) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_game *game)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = game->map[(int)y][(int)x];
	z1 = game->map[(int)y1][(int)x1];


	//-----zoom-----
	x *= game->zoom;
	y *= game->zoom;
	x1 *= game->zoom;
	y1 *= game->zoom;

	//-----color-----
	game->color = (z || z1) ? 0xe80c0c : 0xffffff; //red || white

	//-----3D-----
	if (!game->twod)
	{
		isometric(&x, &y, z, game);
		isometric(&x1, &y1, z1, game);
	}
	
	//-----shift-----
	x += game->shift_x;
	y += game->shift_y;
	x1 += game->shift_x;
	y1 += game->shift_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, game->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (x < game->width - 1)
				bresenham(x, y, x + 1, y, game);
			if (y < game->height - 1)
				bresenham(x, y, x, y + 1, game);
			x++;
		}
		y++;
	}
}