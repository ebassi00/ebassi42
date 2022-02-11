/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:47 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/11 15:51:59 by ebassi           ###   ########.fr       */
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

typedef struct s_game {
	int	**map;
	int	width;
	int	height;
}				t_game;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	t_game	*game;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_data	*mlx_init_root(char *parsing_map);
void	create_map(t_data *root, char *parsing_map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_ber(char *parsing_map);

#endif