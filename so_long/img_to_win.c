/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:23 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/21 16:56:51 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	img_to_win(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->img->prev_x = game->img->player_x;
	game->img->prev_y = game->img->player_y;
	if (!game->img->xpm_image)
		game->img->xpm_image = malloc (sizeof(char) * game->width + 1);
	if (!game->img->collectible_count)
		init_collectible_count(game, i, j);
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
