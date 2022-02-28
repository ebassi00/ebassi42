/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:13:25 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/28 15:41:20 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validity_height(t_game *game, int i)
{
	if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		return (0);
	i++;
	return (1);
}

int	validity_width(t_game *game, int i)
{
	if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		return (0);
	i++;
	return (1);
}

int	val_height_width(t_game *game, int i)
{
	while (i < game->width)
	{
		if (!validity_height(game, i))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (!validity_width(game, i))
			return (0);
		i++;
	}
	return (1);
}

int	val_pl_coll(int i, t_game *game, int j)
{
	int	num_player;
	int	num_coll;

	num_player = 0;
	num_coll = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				num_player++;
			else if (game->map[i][j] == 'C')
				num_coll++;
			j++;
		}
		i++;
	}
	if (num_player != 1 || num_coll < 1)
		return (0);
	return (1);
}

int	check_validity(t_game *game)
{
	int	i;
	int	j;
	int	num_player;
	int	num_coll;

	i = 0;
	j = 0;
	num_player = 0;
	num_coll = 0;
	if (!val_height_width(game, i) || !val_pl_coll(i, game, j))
	{
		free_all(game);
		return (0);
	}
	return (1);
}
