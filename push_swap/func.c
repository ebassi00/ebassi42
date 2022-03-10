/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/07 15:17:00 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
