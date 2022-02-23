/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:13:25 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/22 17:28:33 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	while (i < game->width)
	{
		if (game->map[0][i] == '0' || game->map[game->height-1][i] == '0')
		{
			ft_putstr_fd("Non valid map\n", 0);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] == '0' || game->map[i][game->width-1] == '0')
		{
			ft_putstr_fd("Non valid map\n", 0);
			return (0);
		}
		i++;
	}
	i = 0;
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
	{
		ft_putstr_fd("Number of players / collectible not valid\n", 0);
		return (0);
	}
	return (1);
}