/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:18:02 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/14 14:32:25 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(t_game *game, char *parsing_file)
{
	int		fd;
	char	*res;
	int		width;

	res = 0;
	width = 0;
	fd = open(parsing_file, O_RDONLY);
	if (!fd)
		return (0);
	res = get_next_line(fd);
	width = ft_rowcount(res, ' ');
	close(fd);
	return (width);
}

int	get_height(t_game *game, char *parsing_file)
{
	int		fd;
	char	*res;
	int		height;

	res = 0;
	height = 0;
	fd = open(parsing_file, O_RDONLY);
	if (!fd)
		return (0);
	while ((res = get_next_line(fd)) != NULL)
	{
		height++;
		free(res);
	}
	close(fd);
	return (height);
}

void	handle_file(t_game *game, char *parsing_file)
{
	int	width;
	int	height;

	if (check_ber(parsing_file))
	{
		game->width = get_width(game, parsing_file);
		game->height = get_height(game, parsing_file);
	}
	else
	{
		printf("Estensione non riconosciuta!");
		exit (0);
	}
	printf("width: %d height: %d\n", game->width, game->height);
}

int		check_ber(char *parsing_map)
{
	int	i;

	i = 0;
	while (parsing_map[i])
	{
		if (parsing_map[i] == '.')
		{
			if (parsing_map[i + 1] == 'f' && parsing_map[i + 2] \
				== 'd' && parsing_map[i + 3] == 'f' && !parsing_map[i + 4])
				return (1);
		}
		i++;
	}
	return (0);
}