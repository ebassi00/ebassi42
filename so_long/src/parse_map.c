/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:23:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/28 18:33:37 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_width(char *parsing_file)
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
	width = ft_strlen(res) - 1;
	free(res);
	close(fd);
	return (width);
}

int	get_height(char *parsing_file)
{
	int		fd;
	char	*res;
	int		height;

	res = 0;
	height = 0;
	fd = open(parsing_file, O_RDONLY);
	if (!fd)
		return (0);
	res = get_next_line(fd);
	while (res != NULL)
	{
		height++;
		free(res);
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
	return (height);
}
