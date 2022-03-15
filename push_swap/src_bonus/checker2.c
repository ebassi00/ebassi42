/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:52:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:18:31 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

int	check_integer(char *str)
{
	int		i;
	char	**nbrs;

	i = 0;
	nbrs = ft_split(str, ' ');
	while (nbrs[i])
	{
		if (!is_integer(nbrs[i]))
		{
			free_nbrs(nbrs);
			return (0);
		}
		i++;
	}
	free_nbrs(nbrs);
	return (1);
}

void	handle_arg(t_game *game, char **nums, char *argv[], int i)
{
	int	j;

	j = 0;
	free(game->stack_a);
	free(game->stack_b);
	nums = ft_split(argv[1], ' ');
	i = 0;
	while (nums[i])
		i++;
	game->stack_a = malloc(sizeof(int *) * i);
	game->stack_b = malloc(sizeof(int *) * i);
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
	char	**nums;

	i = 1;
	j = 0;
	nums = 0;
	game->stack_a = malloc(sizeof(int *) * argc - 1);
	game->stack_b = malloc(sizeof(int *) * argc - 1);
	if (argc == 2)
		handle_arg(game, nums, argv, i);
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

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (check_integer(argv[1]))
			return (1);
		return (0);
	}
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ordered_stack(t_game *game)
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
