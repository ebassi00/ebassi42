/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:47:01 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/14 15:11:03 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_game *game)
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
				break ;
			}
			i++;
		}
		j = game->len_a - 1;
		while (j > 0)
		{
			if (game->stack_a[i] >= nbr_min && game->stack_a[j] <= nbr_max)
			{
				hold_second = j;
				break ;
			}
			j--;
		}
		if (i == 0)
		{
			ft_pb(game);
			ft_putstr_fd("pb\n", 1);
		}
		else if ((split - i) > (j - split))
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
		else if ((split - i) < (j - split))
		{
			while (j != game->len_a)
			{
				ft_rra(game);
				ft_putstr_fd("rra\n", 1);
				j++;
			}
			if (j == game->len_a)
			{
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

void	push_back_a2(int j, t_game *game)
{
	if (j <= game->len_b / 2)
	{
		while (j != 0)
		{
			ft_rb(game);
			ft_putstr_fd("rb\n", 1);
			j--;
		}
		ft_pa(game);
		ft_putstr_fd("pa\n", 1);
	}
	else if (j > game->len_b / 2)
	{
		while (j != game->len_b - 1)
		{
			ft_rrb(game);
			ft_putstr_fd("rrb\n", 1);
			j++;
		}
		ft_rrb(game);
		ft_putstr_fd("rrb\n", 1);
		ft_pa(game);
		ft_putstr_fd("pa\n", 1);
	}
}

void	push_back_a(t_game *game)
{
	int	max;
	int	i;
	int	j;

	max = -2147483648;
	i = 0;
	j = 0;
	while (i < game->len_b)
	{
		if (game->stack_b[i] > max)
		{
			max = game->stack_b[i];
			j = i;
		}
		i++;
	}
	push_back_a2(j, game);
}

void	sort_100(t_game *game)
{
	int	len;

	len = 0;
	get_chunk(game, 1, 20);
	get_chunk(game, 21, 40);
	get_chunk(game, 41, 60);
	get_chunk(game, 61, 80);
	get_chunk(game, 81, 100);
	len = game->len_b;
	while (len--)
		push_back_a(game);
}

void	sort_500(t_game *game)
{
	int	len;

	len = 0;
	get_chunk(game, 1, 45);
	get_chunk(game, 46, 90);
	get_chunk(game, 91, 135);
	get_chunk(game, 136, 180);
	get_chunk(game, 181, 225);
	get_chunk(game, 226, 270);
	get_chunk(game, 271, 315);
	get_chunk(game, 316, 360);
	get_chunk(game, 361, 405);
	get_chunk(game, 406, 450);
	get_chunk(game, 451, 500);
	len = game->len_b;
	while (len--)
		push_back_a(game);
}
