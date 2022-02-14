/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:06:46 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/14 16:43:12 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_game {
	int		width;
	int		height;
	int		**map;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	angle;
	int		z_axis;
	int		twod;

	void	*mlx_ptr;
	void	*mlx_win;
}				t_game;

void	handle_file(t_game *game, char *parsing_file);
int		check_ber(char *parsing_map);
void	fill_matrix(t_game *game, char *filename);
void	bresenham(float x, float y, float x1, float y1, t_game *game);
void	draw(t_game *game);

#endif