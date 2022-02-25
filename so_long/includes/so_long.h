/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:47 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/25 15:51:17 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_img {
	void	*xpm_image_pl;
	void	*xpm_image_coll;
	void	*xpm_image_exit;
	void	*xpm_image_wall;
	void	*xpm_image_exit2;
	int		img_size_x;
	int		img_size_y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		grass_x;
	int		grass_y;
	int		prev_x;
	int		prev_y;
	int		collectible_count;
	int		move;
}				t_img;

typedef struct s_game {
	char	**map;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	int		x_size;
	int		y_size;
	t_img	*img;
}				t_game;

t_game	*mlx_init_root(char *parsing_map);
void	create_map(t_game *game, char *parsing_map);
int		check_ber(char *parsing_map);
int		get_width(char *parsing_file);
int		get_height(char *parsing_file);
int		fill_matrix(t_game *game, char *filename);
void	img_to_win(t_game *game);
t_img	*img_init(void);
void	move_up(t_game *game, int i, int j);
void	move_down(t_game *game, int i, int j);
void	move_left(t_game *game, int i, int j);
void	move_right(t_game *game, int i, int j);
void	biggest_handle(t_game *game, int i, int j);
void	move_up_wall(t_game *game);
void	move_up_coll(t_game *game, int i, int j);
void	move_up_exit1(t_game *game);
void	move_up_exit2(t_game *game);
void	move_up_else(t_game *game, int i, int j);
void	move_down_wall(t_game *game);
void	move_down_coll(t_game *game, int i, int j);
void	move_down_exit1(t_game *game);
void	move_down_exit2(t_game *game);
void	move_down_else(t_game *game, int i, int j);
void	move_left_wall(t_game *game);
void	move_left_coll(t_game *game, int i, int j);
void	move_left_exit1(t_game *game);
void	move_left_exit2(t_game *game);
void	move_left_else(t_game *game, int i, int j);
void	move_right_wall(t_game *game);
void	move_right_coll(t_game *game, int i, int j);
void	move_right_exit1(t_game *game);
void	move_right_exit2(t_game *game);
void	move_right_else(t_game *game, int i, int j);
void	player_handle(t_game *game, int i, int j);
int		check_validity(t_game *game);
void	free_all(t_game *game);
int		ft_exit(char *str);

#endif