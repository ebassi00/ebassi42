/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:37:33 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:22:54 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*fill_args_char2(char *argv[], int *tmp_arr, int i, int j)
{
	char	**nums;

	nums = ft_split(argv[1], ' ');
	i = 0;
	while (nums[i])
		i++;
	tmp_arr = malloc (sizeof(int *) * i);
	while (nums[j])
	{
		tmp_arr[j] = ft_atoi(nums[j]);
		j++;
	}
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
	return (tmp_arr);
}

int	*fill_args_char(int *tmp_arr, char *argv[], int argc)
{
	int		i;
	int		j;
	char	**nums;

	i = 1;
	j = 0;
	nums = 0;
	tmp_arr = malloc (sizeof(int *) * argc - 1);
	if (argc == 2)
	{
		free(tmp_arr);
		tmp_arr = fill_args_char2(argv, tmp_arr, i, j);
	}
	else
	{
		while (i < argc)
		{
			tmp_arr[j] = ft_atoi(argv[i]);
			i++;
			j++;
		}
	}
	return (tmp_arr);
}

void	fill_args2(t_game *game, char *argv[], int i, int j)
{
	char	**nums;

	nums = 0;
	free(game->stack_a);
	free(game->stack_b);
	nums = ft_split(argv[1], ' ');
	i = 0;
	while (nums[i])
		i++;
	game->stack_a = malloc (sizeof(int *) * i);
	game->stack_b = malloc (sizeof(int *) * i);
	while (nums[j])
	{
		game->stack_a[j] = ft_atoi(nums[j]);
		game->len_a++;
		j++;
	}
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	fill_args(t_game *game, char *argv[], int argc)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	game->stack_a = malloc (sizeof(int *) * argc - 1);
	game->stack_b = malloc (sizeof(int *) * argc - 1);
	if (argc == 2)
		fill_args2(game, argv, i, j);
	else
	{
		while (i < argc)
		{
			game->stack_a[j] = ft_atoi(argv[i]);
			game->len_a++;
			i++;
			j++;
		}
	}
}
