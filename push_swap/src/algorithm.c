/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:47:01 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:05 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_chunk(t_game *game, int nbr_min, int nbr_max, int hold_first)
{
	int	hold_second;
	int	i;
	int	j;
	int	x;
	int	split;

	x = nbr_min;
	while (x <= nbr_max)
	{
		i = 0;
		j = 0;
		split = game->len_a / 2;
		hold_first = get_hold_first(nbr_max, nbr_min, game, hold_first);
		hold_second = get_hold_second(game, nbr_min, nbr_max);
		chunk_decision(hold_first, hold_second, split, game);
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
		while (j != game->len_b)
		{
			ft_rrb(game);
			ft_putstr_fd("rrb\n", 1);
			j++;
		}
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
	get_chunk(game, 1, 20, 0);
	get_chunk(game, 21, 40, 0);
	get_chunk(game, 41, 60, 0);
	get_chunk(game, 61, 80, 0);
	get_chunk(game, 81, 100, 0);
	len = game->len_b;
	while (len--)
		push_back_a(game);
}

void	sort_500(t_game *game)
{
	int	len;

	len = 0;
	get_chunk(game, 1, 45, 0);
	get_chunk(game, 46, 90, 0);
	get_chunk(game, 91, 135, 0);
	get_chunk(game, 136, 180, 0);
	get_chunk(game, 181, 225, 0);
	get_chunk(game, 226, 270, 0);
	get_chunk(game, 271, 315, 0);
	get_chunk(game, 316, 360, 0);
	get_chunk(game, 361, 405, 0);
	get_chunk(game, 406, 450, 0);
	get_chunk(game, 451, 500, 0);
	len = game->len_b;
	while (len--)
		push_back_a(game);
}
