/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:23:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/16 12:37:03 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	width = ft_strlen(res);
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