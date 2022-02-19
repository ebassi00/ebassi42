/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:35:27 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/19 01:20:42 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, int prev_x, int i, int j)
{
	if (game->map[i-1][j] == '1')
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i-1][j] == 'C')
	{
		game->img->player_collect++;
		game->img->collectible_count--;
		game->img->player_x = prev_x;
		game->map[i][j] = '0';
		game->map[i-1][j] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i-1][j] == 'E' && game->img->collectible_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		printf("HAI VINTO!");
		exit (0);
	}
	else if (game->map[i-1][j] == 'E' && game->img->collectible_count != 0)
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else
	{
		game->img->player_x = prev_x;
		game->map[i][j] = game->map[i-1][j];
		game->map[i-1][j] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
}

void	move_down(t_game *game, int prev_x, int i, int j)
{
	if (game->map[i+1][j] == '1')
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i+1][j] == 'C')
	{
		game->img->player_collect++;
		game->img->collectible_count--;
		game->img->player_x = prev_x;
		game->map[i][j] = '0';
		game->map[i+1][j] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i+1][j] == 'E' && game->img->collectible_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		printf("HAI VINTO!");
		exit (0);
	}
	else if (game->map[i+1][j] == 'E' && game->img->collectible_count != 0)
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else
	{
		game->img->player_x = prev_x;
		game->map[i][j] = game->map[i+1][j];
		game->map[i+1][j] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
}

void	move_left(t_game *game, int prev_y, int i, int j)
{
	if (game->map[i][j-1] == '1')
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i][j-1] == 'C')
	{
		game->img->player_collect++;
		game->img->collectible_count--;
		game->img->player_y = prev_y;
		game->map[i][j] = '0';
		game->map[i][j-1] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i][j-1] == 'E' && game->img->collectible_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		printf("HAI VINTO!");
		exit (0);
	}
	else if (game->map[i][j-1] == 'E' && game->img->collectible_count != 0)
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else
	{
		game->img->player_y = prev_y;
		game->map[i][j] = game->map[i][j-1];
		game->map[i][j-1] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
}

void	move_right(t_game *game, int prev_y, int i, int j)
{
	if (game->map[i][j+1] == '1')
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i][j+1] == 'C')
	{
		game->img->player_collect++;
		game->img->collectible_count--;
		game->img->player_y = prev_y;
		game->map[i][j] = '0';
		game->map[i][j+1] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else if (game->map[i][j+1] == 'E' && game->img->collectible_count == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		printf("HAI VINTO!");
		exit (0);
	}
	else if (game->map[i][j+1] == 'E' && game->img->collectible_count != 0)
	{
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
	else
	{
		game->img->player_y = prev_y;
		game->map[i][j] = game->map[i][j+1];
		game->map[i][j+1] = 'P';
		game->img->move++;
		printf("Mosse: %d\n", game->img->move);
		game->img->xpm_image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img->img_size_x, &game->img->img_size_y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->xpm_image, game->img->player_y, game->img->player_x);
	}
}
