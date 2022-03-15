/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:17:59 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:02 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_decision3(int i, t_game *game)
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

void	chunk_decision2(int j, t_game *game)
{
	while (j != game->len_a)
	{
		ft_rra(game);
		ft_putstr_fd("rra\n", 1);
		j++;
	}
	ft_pb(game);
	ft_putstr_fd("pb\n", 1);
}

void	chunk_decision(int i, int j, int split, t_game *game)
{
	if (i == 0 || j == 0)
	{
		ft_pb(game);
		ft_putstr_fd("pb\n", 1);
	}
	else if ((split - i) > (j - split) || (j == split || i == split))
		chunk_decision3(i, game);
	else if ((j - split) == (split - i))
		chunk_decision3(i, game);
	else if ((split - i) < (j - split))
		chunk_decision2(j, game);
}

int	get_hold_first(int nbr_max, int nbr_min, t_game *game, int hold_first)
{
	int	i;

	i = 0;
	while (i < game->len_a)
	{
		if (game->stack_a[i] >= nbr_min && game->stack_a[i] <= nbr_max)
		{
			hold_first = i;
			break ;
		}
		i++;
	}
	return (hold_first);
}

int	get_hold_second(t_game *game, int nbr_min, int nbr_max)
{
	int	j;
	int	hold_second;

	j = game->len_a - 1;
	hold_second = 0;
	while (j >= 0)
	{
		if (game->stack_a[j] >= nbr_min && game->stack_a[j] <= nbr_max)
		{
			hold_second = j;
			break ;
		}
		j--;
	}
	return (hold_second);
}
