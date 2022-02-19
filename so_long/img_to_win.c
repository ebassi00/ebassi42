/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:23 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/18 15:09:24 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*img_init(void)
{
	t_img	*img;
	
	img = malloc (sizeof(t_img));
	img->img_size_x = 64;
	img->img_size_y = 64;
	img->player_x = 0;
	img->player_y = 0;
	img->exit_x = 0;
	img->exit_y = 0;
	img->grass_x = 0;
	img->grass_y = 0;
	img->player_collect = 0;
	img->collectible_count = 0;
	img->move = 0;
	return (img);
}

void	img_to_win(t_game *game)
{
	int	i;
	int	j;
	int	prev_x;
	int	prev_y;

	i = 0;
	j = 0;
	prev_x = game->img->player_x;
	prev_y = game->img->player_y;
	if (!game->img->xpm_image)
		game->img->xpm_image = malloc (sizeof(char) * game->width + 1);
	if (!game->img->collectible_count)
	{
		while (i < game->height)
		{
			j = 0;
			while (j < game->width)
			{
				if (game->map[i][j] == 'C')
					game->img->collectible_count++;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->img->player_x = (i) * 64;
				game->img->player_y = (j) * 64;
				if (prev_x != game->img->player_x && prev_x != 0 && prev_x < game->img->player_x)
					move_up(game, prev_x, i, j);
				else if (prev_x != game->img->player_x && prev_x != 0 && prev_x > game->img->player_x)
					move_down(game, prev_x, i, j);
				else if (prev_y != game->img->player_y && prev_y != 0 && prev_y > game->img->player_y)
					move_right(game, prev_y, i, j);
				else if (prev_y != game->img->player_y && prev_y != 0 && prev_y < game->img->player_y)
					move_left(game, prev_y, i, j);
				else
				{
					game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
					mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
				}
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
			if (game->map[i][j] == '1')
			{
				game->y_size = (i) * 64;
				game->x_size = (j) * 64;
				game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &game->img->img_size_x, &game->img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->x_size, game->y_size);
			}
			else if (game->map[i][j] == 'E')
			{
				game->img->exit_x = (i) * 64;
				game->img->exit_y = (j) * 64;
				if (game->img->collectible_count == 0)
				{
					game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/exit_2.xpm", &game->img->img_size_x, &game->img->img_size_y);
					mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->exit_y, game->img->exit_x);
				}
				else
				{
					game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &game->img->img_size_x, &game->img->img_size_y);
					mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->exit_y, game->img->exit_x);
				}
			}
			else if (game->map[i][j] == 'C')
			{
				game->img->exit_x = (i) * 64;
				game->img->exit_y = (j) * 64;
				game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/collectible.xpm", &game->img->img_size_x, &game->img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->exit_y, game->img->exit_x);
			}
			/*else if (game->map[i][j] == '0') 								//DECOMMENTARE SE SI VUOLE SFONDO SUGLI '0'
			{
				game->img->grass_x = (i) * 64;
				game->img->grass_y = (j) * 64;
				game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/grass.xpm", &game->img->img_size_x, &game->img->img_size_y);
				mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->grass_y, game->img->grass_x);
			}*/
			j++;
		}
		i++;
	}
}
