/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:49:20 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:34 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_this_min(t_game *game)
{
	int	len;
	int	min;

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

int	get_max(t_game *game)
{
	int	len;
	int	max;

	max = -2147483648;
	len = 0;
	while (len < game->len_a)
	{
		if (game->stack_a[len] > max)
			max = game->stack_a[len];
		len++;
	}
	return (max);
}

void	sort_3(t_game *game)
{
	if (game->stack_a[0] < game->stack_a[1] && game->stack_a[0] \
		< game->stack_a[2] && game->stack_a[1] > game->stack_a[2])
	{
		ft_sa(game);
		ft_putstr_fd("sa\n", 1);
	}
	if (game->stack_a[0] < game->stack_a[1] \
		&& game->stack_a[0] > game->stack_a[2])
	{
		ft_rra(game);
		ft_putstr_fd("rra\n", 1);
	}
	if (game->stack_a[0] > game->stack_a[2])
	{
		ft_ra(game);
		ft_putstr_fd("ra\n", 1);
	}
	if (game->stack_a[0] > game->stack_a[1])
	{
		ft_sa(game);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_u6_2(t_game *game)
{
	if (game->stack_b[0] < get_this_min(game))
	{
		ft_pa(game);
		ft_putstr_fd("pa\n", 1);
	}
	else if (game->stack_b[0] > get_max(game))
	{
		ft_pa(game);
		ft_ra(game);
		ft_putstr_fd("pa\nra\n", 1);
	}
	else
	{
		ft_pa(game);
		ft_putstr_fd("pa\n", 1);
		find_smallest(game);
	}
}

void	sort_u6(t_game *game)
{
	if (game->len_a > 3)
	{
		if (game->len_a == 5)
		{
			ft_pb(game);
			ft_putstr_fd("pb\n", 1);
		}
		ft_pb(game);
		ft_putstr_fd("pb\n", 1);
	}
	sort_3(game);
	while (game->len_b)
		sort_u6_2(game);
}
