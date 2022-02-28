/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:24:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/28 18:30:19 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*fill_matrix_wnumbers(char *map_line, char *res);

void	alloc_matrix(t_game *game)
{
	int	i;

	i = 0;
	game->map = malloc (sizeof(char **) * game->height + 1);
	game->map[game->height] = NULL;
	while (i < game->height)
	{
		game->map[i] = malloc (sizeof(char *) * game->width + 1);
		game->map[i][game->width] = '\0';
		i++;
	}
}

int	fill_matrix(t_game *game, char *filename)
{
	int		i;
	int		fd;
	char	*res;

	i = 0;
	if (!game->height || !game->width)
		return (0);
	alloc_matrix(game);
	fd = open(filename, O_RDONLY);
	res = get_next_line(fd);
	while (res != NULL)
	{
		game->map[i] = fill_matrix_wnumbers(game->map[i], res);
		free(res);
		i++;
		res = get_next_line(fd);
	}
	free(res);
	game->map[i] = NULL;
	return (1);
}

char	*fill_matrix_wnumbers(char *map_line, char *res)
{
	int	i;

	i = 0;
	while (res[i] && res[i] != '\n')
	{
		map_line[i] = res[i];
		i++;
	}
	return (map_line);
}
