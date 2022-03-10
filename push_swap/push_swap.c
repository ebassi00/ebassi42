/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/10 16:37:59 by ebassi           ###   ########.fr       */
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

int	*fill_args_char(int *tmp_arr, char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	tmp_arr = malloc (sizeof(int *) * argc - 1);
	while (i < argc)
	{
		tmp_arr[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (tmp_arr);
}

int	check_args(int argc, char *argv[])
{
	(void)argv;
	(void)argc;
	return (1);
}

void	change_nm(t_game *game, int argc, char *argv[])
{
	int	*tmp_arr;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	tmp_arr = NULL;
	tmp_arr = fill_args_char(tmp_arr, argv, argc);
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
	i = 0;
	j = 0;
	while (i < game->len_a)
	{
		j = 0;
		while (j < game->len_a)
		{
			if (game->stack_a[i] == tmp_arr[j])
			{
				game->stack_a[i] = j + 1;
				break;
			}
			// break;
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < game->len_a)
	// {
	// 	printf("%d ", tmp_arr[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (i < game->len_a)
	// {
	// 	printf("%d ", game->stack_a[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < game->len_a)
	// {
	// 	printf("%d ", tmp_arr[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (i < game->len_a)
	// {
	// 	printf("%d ", game->stack_a[i]);
	// 	i++;
	// }
	// free(tmp_arr);
}

int main(int argc, char *argv[])
{
	t_game *game;
	int	i;
	int	max;

	i = 0;
	max = 0;
	game = init_game();
	if (!check_args(argc, argv))
		return (0);
	fill_args(game, argv, argc);
	change_nm(game, argc, argv);
	// ------- TESTING ALGORITHM FROM HERE -------
	// merge_algo(game);
	if (game->len_a < 12)
	{
		while (game->len_a - 1)
		find_smallest(game);
		while(game->len_b)
		{
			ft_pa(game);
			ft_putstr_fd("pa\n", 1);
		}
	}
	else if (game->len_a == 100)
		sort_100(game);
	
	/*while (game->len_a - 1)
		find_smallest(game);
	while(game->len_b)
	{
		ft_pa(game);
		ft_putstr_fd("pa\n", 1);
	}*/
	
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