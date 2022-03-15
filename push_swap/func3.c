/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:51:20 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 12:51:55 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_game *game)
{
	int	tmp;
	int	len;

	len = game->len_a - 1;
	tmp = game->stack_a[game->len_a - 1];
	if (game->stack_a)
	{
		while (len >= 0)
		{
			game->stack_a[len] = game->stack_a[len - 1];
			len--;
		}
		game->stack_a[0] = tmp;
	}
}

void	ft_rrb(t_game *game)
{
	int	tmp;
	int	len;

	len = game->len_b - 1;
	tmp = game->stack_b[game->len_b - 1];
	if (game->stack_b)
	{
		while (len >= 0)
		{
			game->stack_b[len] = game->stack_b[len - 1];
			len--;
		}
		game->stack_b[0] = tmp;
	}
}

void	ft_rrr(t_game *game)
{
	ft_rra(game);
	ft_rrb(game);
}
