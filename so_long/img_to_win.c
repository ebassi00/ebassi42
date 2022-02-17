/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:23 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/16 16:11:41 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_img *img)
{
	img->img_size_x = 64;
	img->img_size_y = 64;
	img->player_x = 0;
	img->player_y = 0;
	img->exit_x = 0;
	img->exit_y = 0;
	img->grass_x = 0;
	img->grass_y = 0;
}

void	img_to_win(t_game *game)
{
	t_img	*img;
	int		i;
	int		j;

	img = malloc (sizeof(t_img));
	img_init(img);
	i = 0;
	j = 0;
	img->xpm_image = malloc (sizeof(char) * game->width + 1);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
			{
				img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &img->img_size_x, &img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, img->xpm_image, game->x_size, game->y_size);
			}
			game->x_size += 64;
			j++;
		}
		game->y_size += 64;
		game->x_size = 64;
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				img->player_x = (i + 1) * 64;
				img->player_y = (j + 1) * 64;
				img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &img->img_size_x, &img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, img->xpm_image, img->player_y, img->player_x);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
			{
				img->exit_x = (i + 1) * 64;
				img->exit_y = (j + 1) * 64;
				img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &img->img_size_x, &img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, img->xpm_image, img->exit_y, img->exit_x);
			}
			else if (game->map[i][j] == 'C')
			{
				img->exit_x = (i + 1) * 64;
				img->exit_y = (j + 1) * 64;
				img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/collectible.xpm", &img->img_size_x, &img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, img->xpm_image, img->exit_y, img->exit_x);
			}
			else if (game->map[i][j] == '0')
			{
				img->grass_x = (i + 1) * 64;
				img->grass_y = (j + 1) * 64;
				img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/grass.xpm", &img->img_size_x, &img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, img->xpm_image, img->grass_y, img->grass_x);
			}
			j++;
		}
		i++;
	}
}
