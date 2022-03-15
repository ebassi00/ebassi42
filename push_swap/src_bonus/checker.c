/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:22:22 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:23:32 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->stack_a = 0;
	game->stack_b = 0;
	game->len_a = 0;
	game->len_b = 0;
	return (game);
}

void	handle_result_line2(char *line, t_game *game)
{
	if (!(ft_strncmp(line, "rb", ft_strlen(line) - 1)))
		ft_rb(game);
	else if (!(ft_strncmp(line, "rr", ft_strlen(line) - 1)))
		ft_rr(game);
	else if (!(ft_strncmp(line, "sb", ft_strlen(line) - 1)))
		ft_sb(game);
	else if (!(ft_strncmp(line, "ss", ft_strlen(line) - 1)))
		ft_ss(game);
	else
	{
		ft_exit("Error\n");
		exit(0);
	}
}

void	handle_result_line(char *line, t_game *game)
{
	if (!(ft_strncmp(line, "sa", ft_strlen(line) - 1)))
		ft_sa(game);
	else if (!(ft_strncmp(line, "pa", ft_strlen(line) - 1)))
		ft_pa(game);
	else if (!(ft_strncmp(line, "pb", ft_strlen(line) - 1)))
		ft_pb(game);
	else if (!(ft_strncmp(line, "rra", ft_strlen(line) - 1)))
		ft_rra(game);
	else if (!(ft_strncmp(line, "rrb", ft_strlen(line) - 1)))
		ft_rrb(game);
	else if (!(ft_strncmp(line, "rrr", ft_strlen(line) - 1)))
		ft_rrr(game);
	else if (!(ft_strncmp(line, "ra", ft_strlen(line) - 1)))
		ft_ra(game);
	else
		handle_result_line2(line, game);
}

void	read_finish(char *line, t_game *game)
{
	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			ft_exit("Error\n");
			exit(0);
		}
		handle_result_line(line, game);
		free(line);
		line = get_next_line(0);
	}
	if (ordered_stack(game) > 0)
		ft_exit("\nOK\n");
	else
		ft_exit("\nKO\n");
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
	line = NULL;
	if (argc < 2)
		return (0);
	fill_args(game, argv, argc);
	if (!check_args(argc, argv) || !check_duplicates(game))
	{
		free_all2(game);
		ft_exit("Error\n");
		return (0);
	}
	read_finish(line, game);
	free_all2(game);
	return (0);
}
