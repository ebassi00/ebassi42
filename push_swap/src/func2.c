/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:50:12 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:10 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_game *game)
{
	int	tmp;
	int	len;

	tmp = game->stack_a[0];
	len = 0;
	if (game->stack_a)
	{
		while (len < game->len_a - 1)
		{
			game->stack_a[len] = game->stack_a[len + 1];
			len++;
		}
		game->stack_a[len] = tmp;
	}
}

void	ft_rb(t_game *game)
{
	int	tmp;
	int	len;

	tmp = game->stack_b[0];
	len = 0;
	if (game->stack_b)
	{
		while (len < game->len_b - 1)
		{
			game->stack_b[len] = game->stack_b[len + 1];
			len++;
		}
		game->stack_b[len] = tmp;
	}
}

void	ft_rr(t_game *game)
{
	ft_ra(game);
	ft_rb(game);
}
