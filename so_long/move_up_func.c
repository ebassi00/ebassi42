/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/21 16:59:48 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_wall(t_game *game)
{
	game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, \
			"./img/player.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image, game->img->player_y, \
			game->img->player_x);
}

void	move_up_coll(t_game *game, int i, int j)
{
	game->img->collectible_count--;
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'P';
	game->img->move++;
	game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, \
		"./img/player.xpm", &game->img->img_size_x, \
		&game->img->img_size_y);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image, game->img->player_y, \
		game->img->player_x);
}

void	move_up_exit1(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->img->move++;
	printf("HAI VINTO!");
	exit (0);
}

void	move_up_exit2(t_game *game)
{
	game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, \
			"./img/player.xpm", &game->img->img_size_x, \
			&game->img->img_size_y);
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image, game->img->player_y, \
			game->img->player_x);
}

void	move_up_else(t_game *game, int i, int j)
{
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = game->map[i - 1][j];
	game->map[i - 1][j] = 'P';
	game->img->move++;
	game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, \
		"./img/player.xpm", &game->img->img_size_x, \
		&game->img->img_size_y);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image, game->img->player_y, \
		game->img->player_x);
}
