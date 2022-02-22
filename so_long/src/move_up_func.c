/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/22 17:06:21 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_pl, game->img->player_y, \
			game->img->player_x);
}

void	move_up_coll(t_game *game, int i, int j)
{
	game->img->collectible_count--;
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
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
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img->xpm_image_pl, game->img->player_y, \
			game->img->player_x);
}

void	move_up_else(t_game *game, int i, int j)
{
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = game->map[i - 1][j];
	game->map[i - 1][j] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}
