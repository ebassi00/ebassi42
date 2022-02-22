/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:35:27 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/22 16:22:52 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == '1')
		move_up_wall(game);
	else if (game->map[i - 1][j] == 'C')
		move_up_coll(game, i, j);
	else if (game->map[i - 1][j] == 'E' && game->img->collectible_count == 0)
		move_up_exit1(game);
	else if (game->map[i - 1][j] == 'E' && game->img->collectible_count != 0)
		move_up_exit2(game);
	else
		move_up_else(game, i, j);
}

void	move_down(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == '1')
		move_down_wall(game);
	else if (game->map[i + 1][j] == 'C')
		move_down_coll(game, i, j);
	else if (game->map[i + 1][j] == 'E' && game->img->collectible_count == 0)
		move_down_exit1(game);
	else if (game->map[i + 1][j] == 'E' && game->img->collectible_count != 0)
		move_down_exit2(game);
	else
		move_down_else(game, i, j);
}

void	move_left(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] == '1')
		move_left_wall(game);
	else if (game->map[i][j - 1] == 'C')
		move_left_coll(game, i, j);
	else if (game->map[i][j - 1] == 'E' && game->img->collectible_count == 0)
		move_left_exit1(game);
	else if (game->map[i][j - 1] == 'E' && game->img->collectible_count != 0)
		move_left_exit2(game);
	else
		move_left_else(game, i, j);
}

void	move_right(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] == '1')
		move_right_wall(game);
	else if (game->map[i][j + 1] == 'C')
		move_right_coll(game, i, j);
	else if (game->map[i][j + 1] == 'E' && game->img->collectible_count == 0)
		move_right_exit1(game);
	else if (game->map[i][j + 1] == 'E' && game->img->collectible_count != 0)
		move_right_exit2(game);
	else
		move_right_else(game, i, j);
}
