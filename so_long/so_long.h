/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:47 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/16 16:11:18 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_game {
	char	**map;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	int		x_size;
	int		y_size;
}				t_game;

typedef struct	s_img {
	void	*xpm_image;
	int		img_size_x;
	int		img_size_y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		grass_x;
	int		grass_y;
}				t_img;

t_game	*mlx_init_root(char *parsing_map);
void	create_map(t_game *game, char *parsing_map);
int		check_ber(char *parsing_map);
int		get_width(t_game *game, char *parsing_file);
int		get_height(t_game *game, char *parsing_file);
void	fill_matrix(t_game *game, char *filename);
void	img_to_win(t_game *game);

#endif