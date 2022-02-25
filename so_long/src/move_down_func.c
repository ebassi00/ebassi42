/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:28:04 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 14:36:33 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_down_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_down_coll(t_game *game, int i, int j)
{
	game->img->collectible_count--;
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = '0';
	game->map[i + 1][j] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_down_exit1(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->img->move++;
	free_all(game);
	ft_exit("HAI VINTO!\n");
}

void	move_down_exit2(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}

void	move_down_else(t_game *game, int i, int j)
{
	game->img->player_x = game->img->prev_x;
	game->map[i][j] = game->map[i + 1][j];
	game->map[i + 1][j] = 'P';
	game->img->move++;
	mlx_put_image_to_window(game->mlx, game->win, \
		game->img->xpm_image_pl, game->img->player_y, \
		game->img->player_x);
}
