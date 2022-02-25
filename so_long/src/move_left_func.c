/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:25:07 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 14:36:29 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_left_coll(t_game *game, int i, int j)
{
	game->img->collectible_count--;
	game->img->player_y = game->img->prev_y;
	game->map[i][j] = '0';
	game->map[i][j - 1] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_left_exit1(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->img->move++;
	free_all(game);
	ft_exit("HAI VINTO!\n");
}

void	move_left_exit2(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_left_else(t_game *game, int i, int j)
{
	game->img->player_y = game->img->prev_y;
	game->map[i][j] = game->map[i][j - 1];
	game->map[i][j - 1] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}
