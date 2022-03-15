/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:39:17 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:23:10 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fast_sort(int *tmp_arr, t_game *game)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	j = 0;
	while (i < game->len_a - 1)
	{
		j = i + 1;
		while (j < game->len_a)
		{
			if (tmp_arr[j] < tmp_arr[i])
			{
				tmp = tmp_arr[i];
				tmp_arr[i] = tmp_arr[j];
				tmp_arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tmp_arr);
}

void	change_nm(t_game *game, int argc, char *argv[])
{
	int	*tmp_arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp_arr = NULL;
	tmp_arr = fill_args_char(tmp_arr, argv, argc);
	tmp_arr = fast_sort(tmp_arr, game);
	while (i < game->len_a)
	{
		j = 0;
		while (j < game->len_a)
		{
			if (game->stack_a[i] == tmp_arr[j])
			{
				game->stack_a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tmp_arr);
}

int	check_ordered(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->len_b)
		return (-1);
	while (i < game->len_a)
	{
		j = i + 1;
		while (j < game->len_a)
		{
			if (!(game->stack_a[i] < game->stack_a[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_all(t_game *game)
{
	free(game->stack_a);
	free(game->stack_b);
	free(game);
}
