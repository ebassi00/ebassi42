/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:37 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/11 16:40:08 by ebassi           ###   ########.fr       */
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

void	fill_args(t_game *game, char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	game->stack_a = malloc (sizeof(int *) * argc - 1);
	game->stack_b = malloc (sizeof(int *) * argc - 1);
	while (i < argc)
	{
		game->stack_a[j] = ft_atoi(argv[i]);
		game->len_a++;
		i++;
		j++;
	}
}

int	check_args(int argc, char *argv[])
{
	(void)argv;
	(void)argc;
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

	i = 0;
	max = 0;
	game = init_game();
	if (!check_args(argc, argv))
		return (0);
	fill_args(game, argv, argc);
	line = get_next_line(0);
	/*if (!line)
		ft_exit("Error\n");*/
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
		line = get_next_line(0);
	}
	// ft_putstr_fd("\n", 1);
	if (ordered_stack(game))
		ft_exit("\nOK\n");
	else if (!(ordered_stack(game)))
		ft_exit("\nKO\n");
	// max = MAX(game->len_a, game->len_b);
	// while (i < max)
	// {
	// 	printf("%d	%d\n", game->stack_a[i], game->stack_b[i]);
	// 	i++;
	// }
}