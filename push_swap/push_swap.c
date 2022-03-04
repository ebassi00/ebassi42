/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/04 15:22:02 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	*init_game()
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

int main(int argc, char *argv[])
{
	t_game *game;
	int	i;
	int	max;

	i = 0;
	max = 0;
	game = init_game();
	fill_args(game, argv, argc);
	// ------- TESTING ALGORITHM FROM HERE -------
	while (game->len_a - 1)
		find_smallest(game);
	while(game->len_b)
		ft_pa(game);
	// ------- TO HERE -------
	max = MAX(game->len_a, game->len_b);
	while (i < max)
	{
		printf("%d	%d\n", game->stack_a[i], game->stack_b[i]);
		i++;
	}
	free(game->stack_a);
	free(game->stack_b);
	free(game);
	return (0);
}