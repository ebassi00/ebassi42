/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:37 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/14 13:33:49 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	game->stack_a = 0;
	game->stack_b = 0;
	game->len_a = 0;
	game->len_b = 0;
	return (game);
}

int	checkInteger(char *str)
{
	int		i;
	char	**nbrs;

	i = 0;
	nbrs = ft_split(str, ' ');
	while (nbrs[i])
	{
		if (!isInteger(nbrs[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_args(t_game *game, char *argv[], int argc)
{
	int		i;
	int		j;
	char	**nums;

	i = 1;
	j = 0;
	nums = 0;
	game->stack_a = malloc (sizeof(int *) * argc - 1);
	game->stack_b = malloc (sizeof(int *) * argc - 1);
	if (argc == 2)
	{
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
	}
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
		if (checkInteger(argv[1]))
			return (1);
		return (0);
	}
	while (i < argc)
	{
		if (!isInteger(argv[i]))
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

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;
	int		max;
	char	*line;
	int		res;

	i = 0;
	res = 0;
	max = 0;
	game = init_game();
	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
	{
		ft_exit("Error\n");
		return (0);
	}
	fill_args(game, argv, argc);
	if (!(check_duplicates(game)))
	{
		ft_exit("Error\n");
		return (0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (!(ft_strncmp(line, "sa", 2)))
			ft_sa(game);
		else if (!(ft_strncmp(line, "pa", 2)))
			ft_pa(game);
		else if (!(ft_strncmp(line, "pb", 2)))
			ft_pb(game);
		else if (!(ft_strncmp(line, "rra", 3)))
			ft_rra(game);
		else if (!(ft_strncmp(line, "rrb", 3)))
			ft_rrb(game);
		else if (!(ft_strncmp(line, "rrr", 3)))
			ft_rrr(game);
		else if (!(ft_strncmp(line, "ra", 2)))
			ft_ra(game);
		else if (!(ft_strncmp(line, "rb", 2)))
			ft_rb(game);
		else if (!(ft_strncmp(line, "rr", 2)))
			ft_rr(game);
		else if (!(ft_strncmp(line, "sb", 2)))
			ft_sb(game);
		else if (!(ft_strncmp(line, "ss", 2)))
			ft_ss(game);
		else
		{
			ft_exit("Error\n");
			return (0);
		}
		line = get_next_line(0);
	}
	if (ordered_stack(game) > 0)
		ft_exit("\nOK\n");
	else
		ft_exit("\nKO\n");
}
