/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:05:01 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_integer(char *str)
{
	int		i;
	char	**nbrs;

	i = 0;
	nbrs = ft_split(str, ' ');
	while (nbrs[i])
	{
		if (!is_integer(nbrs[i]))
			return (0);
		i++;
	}
	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
	return (1);
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

void	sorting_algo(t_game *game)
{
	if (game->len_a <= 5)
		sort_u6(game);
	else if (game->len_a == 100)
		sort_100(game);
	else if (game->len_a == 500)
		sort_500(game);
	else
	{
		while (game->len_a - 1)
			find_smallest(game);
		while (game->len_b)
		{
			ft_pa(game);
			ft_putstr_fd("pa\n", 1);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;
	int		max;

	i = 0;
	max = 0;
	game = init_game();
	if (!check_args(argc, argv))
		return (0);
	fill_args(game, argv, argc);
	if (!check_duplicates(game) || check_ordered(game) > 0)
	{
		free_all(game);
		return (0);
	}
	change_nm(game, argc, argv);
	sorting_algo(game);
	free_all(game);
	return (0);
}
