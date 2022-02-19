/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:24:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/19 01:43:02 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_matrix_wnumbers(char *map_line, char *res);

void	fill_matrix(t_game *game, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	*res;

	i = 0;
	j = 0;
	game->map = malloc (sizeof(char *) * game->height + 1);
	game->map[game->height] = NULL;
	while (i <= game->height)
	{
		game->map[i++] = malloc (sizeof(char *) * game->width + 1);
		game->map[game->width] = NULL;
	}
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

char	*fill_matrix_wnumbers(char *map_line, char *res)
{
	int		i;

	i = 0;
	while (res[i] && res[i] != '\n')
	{
		map_line[i] = res[i];
		i++;
	}
	return (map_line);
}
