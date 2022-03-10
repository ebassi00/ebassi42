/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:39:03 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/07 15:31:57 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_game *game)
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
	exec_swap(game, min);
}

void	exec_middle(t_game *game, int min)
{
	while (game->stack_a[0] != min)
	{
		ft_ra(game);
		ft_putstr_fd("ra\n", 1);
	}
	if (game->stack_a[0] == min)
	{
		ft_pb(game);
		ft_putstr_fd("pb\n", 1);
	}
}

void	exec_swap(t_game *game, int min)
{
	int	i;

	i = 0;
	if (game->stack_a[0] == min)
	{
		ft_pb(game);
		ft_putstr_fd("pb\n", 1);
	}
	else if (game->stack_a[1] == min)
	{
		ft_sa(game);
		ft_pb(game);
		ft_putstr_fd("sa\npb\n", 1);
	}
	else if (game->stack_a[game->len_a - 1] == min)
	{
		ft_rra(game);
		ft_pb(game);
		ft_putstr_fd("rra\npb\n", 1);
	}
	else if (game->stack_a[game->len_a - 2] == min)
	{
		ft_rra(game);
		ft_rra(game);
		ft_pb(game);
		ft_putstr_fd("rra\nrra\npb\n", 1);
	}
	else
		exec_middle(game, min);
}
