/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:08 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_game *game)
{
	int	tmp;

	tmp = game->stack_a[0];
	game->stack_a[0] = game->stack_a[1];
	game->stack_a[1] = tmp;
}

void	ft_sb(t_game *game)
{
	int	tmp;

	tmp = game->stack_b[0];
	game->stack_b[0] = game->stack_b[1];
	game->stack_b[1] = tmp;
}

void	ft_ss(t_game *game)
{
	ft_sa(game);
	ft_sb(game);
}

void	ft_pa(t_game *game)
{
	int	len;
	int	tmp;

	len = game->len_a;
	tmp = 0;
	if (game->stack_b)
	{
		while (len >= 0)
		{
			game->stack_a[len + 1] = game->stack_a[len];
			len--;
		}
		game->stack_a[0] = game->stack_b[0];
		game->len_a++;
		len = 0;
		while (len < game->len_b)
		{
			game->stack_b[len] = game->stack_b[len + 1];
			len++;
		}
		game->len_b--;
	}
}

void	ft_pb(t_game *game)
{
	int	len;
	int	tmp;

	len = game->len_b;
	tmp = 0;
	if (game->stack_a)
	{
		while (len >= 0)
		{
			game->stack_b[len + 1] = game->stack_b[len];
			len--;
		}
		game->stack_b[0] = game->stack_a[0];
		game->len_b++;
		len = 0;
		while (len < game->len_a)
		{
			game->stack_a[len] = game->stack_a[len + 1];
			len++;
		}
		game->len_a--;
	}
}
