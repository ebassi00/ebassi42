/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:33:24 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/14 15:14:50 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*fill_matrix_wnumbers(int *map_line, char *res);

void	fill_matrix(t_game *game, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	*res;

	i = 0;
	j = 0;
	game->map = malloc (sizeof(int*) * game->height + 1);
	while (i <= game->height)
		game->map[i++] = malloc (sizeof(int*) * game->width + 1);
	fd = open(filename, O_RDONLY);
	i = 0;
	while ((res = get_next_line(fd)) != NULL)
	{
		game->map[i] = fill_matrix_wnumbers(game->map[i], res);
		free(res);
		i++;
	}
	game->map[i] = NULL;
}

int	*fill_matrix_wnumbers(int *map_line, char *res)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(res, ' ');
	while (numbers[i])
	{
		map_line[i] = ft_atoi(numbers[i]);
		i++;
		free(numbers[i]);
	}
	free(numbers);
	return (map_line);
}