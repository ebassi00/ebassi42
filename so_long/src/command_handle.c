/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:22:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/22 17:17:17 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_handle(t_game *game, int i, int j)
{
	game->img->player_x = (i) * 64;
	game->img->player_y = (j) * 64;
	if (game->img->prev_x != game->img->player_x && game->img->prev_x != 0 \
		&& game->img->prev_x < game->img->player_x)
		move_up(game, i, j);
	else if (game->img->prev_x != game->img->player_x && game->img->prev_x != 0 \
			&& game->img->prev_x > game->img->player_x)
		move_down(game, i, j);
	else if (game->img->prev_y != game->img->player_y && game->img->prev_y != 0 \
			&& game->img->prev_y > game->img->player_y)
		move_right(game, i, j);
	else if (game->img->prev_y != game->img->player_y && game->img->prev_y != 0 \
			&& game->img->prev_y < game->img->player_y)
		move_left(game, i, j);
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_pl, game->img->player_y, \
			game->img->player_x);
	}
}

void	wall_handle(t_game *game, int i, int j)
{
	game->y_size = (i) * 64;
	game->x_size = (j) * 64;
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_wall, game->x_size, game->y_size);
}

void	exit_handle(t_game *game, int i, int j)
{
	game->img->exit_x = (i) * 64;
	game->img->exit_y = (j) * 64;
	if (game->img->collectible_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_exit2, \
			game->img->exit_y, game->img->exit_x);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_exit, game->img->exit_y, \
			game->img->exit_x);
	}
}

void	collectible_handle(t_game *game, int i, int j)
{
	game->img->exit_x = (i) * 64;
	game->img->exit_y = (j) * 64;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_coll, game->img->exit_y, \
		game->img->exit_x);
}

void	biggest_handle(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		wall_handle(game, i, j);
	else if (game->map[i][j] == 'E')
		exit_handle(game, i, j);
	else if (game->map[i][j] == 'C')
		collectible_handle(game, i, j);
}
