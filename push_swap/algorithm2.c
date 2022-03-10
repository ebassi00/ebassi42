/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:47:01 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/10 16:02:08 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min(t_game *game)
{
	int	len;
	int min;

	min = 2147483647;
	len = 0;
	while (len < game->len_a)
	{
		if (game->stack_a[len] < min)
			min = game->stack_a[len];
		len++;
	}
	return (min);
}

void	get_chunk(t_game *game, int nbr_min, int nbr_max)
{
	int	hold_first;
	int	hold_second;
	int	i;
	int	j;
	int	x;
	int	split;

	i = 0;
	x = nbr_min;
	j = 0;
	hold_first = 0;
	hold_second = 0;
	while (x <= nbr_max)
	{
		split = game->len_a / 2;
		while (i < game->len_a)
		{
			if (game->stack_a[i] >= nbr_min && game->stack_a[i] <= nbr_max)
			{
				hold_first = i;
				break;
			}
			i++;
		}
		j = game->len_a - 1;
		while (j > 0)
		{
			if (game->stack_a[i] >= nbr_min && game->stack_a[j] <= nbr_max)
			{
				hold_second = j;
				break;
			}
			j--;
		}
		// printf("hold_first: %d i: %d hold_second: %d j: %d len: %d split: %d\n", game->stack_a[i], i, game->stack_a[j], j, game->len_a-1, split);
		if (i == 0)
		{
			ft_pb(game);
			ft_putstr_fd("pb\n", 1);
		}
		else if ((split - i) > (j - split))
		{
			// i = 0;
			while (i != 0)
			{
				ft_ra(game);
				ft_putstr_fd("ra\n", 1);
				i--;
			}
			if (i == 0)
			{
				ft_pb(game);
				ft_putstr_fd("pb\n", 1);
			}
		}
		else if ((split - i) < (j - split))
		{
			// j = 0;
			while (j != game->len_a)
			{
				ft_rra(game);
				ft_putstr_fd("rra\n", 1);
				j++;
			}
			if (j == game->len_a)
			{
				// ft_rra(game);
				// ft_putstr_fd("rra\n", 1);
				ft_pb(game);
				ft_putstr_fd("pb\n", 1);
			}
		}
		else if ((j == split || i == split) || (j - split) == (split - i))
		{
			while (i != 0)
			{
				ft_ra(game);
				ft_putstr_fd("ra\n", 1);
				i--;
			}
			if (i == 0)
			{
				ft_pb(game);
				ft_putstr_fd("pb\n", 1);
			}
		}
		x++;
	}
}

void	sort_100(t_game *game)
{
	get_chunk(game, 1, 20);
	get_chunk(game, 21, 40);
	get_chunk(game, 41, 60);
	get_chunk(game, 61, 80);
	// get_chunk(game, 100);
}