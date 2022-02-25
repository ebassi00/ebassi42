/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:23 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 16:01:55 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_collectible_count(t_game *game, int i, int j);
void	place_map(t_game *game, int i, int j);

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
	img->collectible_count = 0;
	img->prev_x = 0;
	img->prev_y = 0;
	img->move = 0;
	return (img);
}

void	init_images(t_game *game)
{
	game->img->xpm_image_pl = mlx_xpm_file_to_image(game->mlx, \
			"./img/player.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	game->img->xpm_image_wall = mlx_xpm_file_to_image(game->mlx, \
			"./img/wall.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	game->img->xpm_image_exit = mlx_xpm_file_to_image(game->mlx, \
			"./img/exit.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	game->img->xpm_image_exit2 = mlx_xpm_file_to_image(game->mlx, \
			"./img/exit_2.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	game->img->xpm_image_coll = mlx_xpm_file_to_image(game->mlx, \
		"./img/collectible.xpm", &game->img->img_size_x, \
		&game->img->img_size_y);
}

void	img_to_win(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->img->prev_x = game->img->player_x;
	game->img->prev_y = game->img->player_y;
	if (!game->img->collectible_count)
		init_collectible_count(game, i, j);
	init_images(game);
	if (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] != '1' && game->map[i][j] != '0') \
				&& (game->map[i][j] != 'C' && game->map[i][j] != 'E') \
				&& game->map[i][j] != 'P')
				ft_exit("Non valid map\n");
			j++;
		}
		i++;
	}
	i = 0;
	place_map(game, i, j);
}

void	init_collectible_count(t_game *game, int i, int j)
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

void	place_map(t_game *game, int i, int j)
{
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				player_handle(game, i, j);
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
			biggest_handle(game, i, j);
			j++;
		}
		i++;
	}
}
