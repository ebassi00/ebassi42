/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:14:59 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/14 16:57:57 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_game *game)
{
	printf("%d\n", key);

	if (key == 126)
		game->shift_y -= 10;
	if (key == 125)
		game->shift_y += 10;
	if (key == 123)
		game->shift_x -= 10;
	if (key == 124)
		game->shift_x += 10;
	if (key == 78)
		game->zoom -= 1;
	if (key == 69)
		game->zoom += 1;
	if (key == 91)
		game->angle += 0.1;
	if (key == 89)
		game->angle -= 0.1;
	if (key == 84)
		game->z_axis += 1;
	if (key == 83)
		game->z_axis -= 1;
	if (key == 53)
		exit (0);
	if (key == 2)
	{
		if (!game->twod)
			game->twod = 1;
		else
			game->twod = 0;
	}
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	draw(game);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 0, 0xffffff, "Press UP DOWN RIGHT LEFT to move | Press D for 2D version");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 20, 0xffffff, "Press PLUS MINUS to zoom IN/OUT | Press ESC to quit");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 40, 0xffffff, "Press 8/7 to reangle");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 60, 0xffffff, "Press 1/2 to move through z-axis");
	return (0);
}

int main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	handle_file(game, argv[1]);
	fill_matrix(game, argv[1]);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 1000, 1000, "FdF");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 0, 0xffffff, "Press UP DOWN RIGHT LEFT to move | Press D for 2D version");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 20, 0xffffff, "Press PLUS MINUS to zoom IN/OUT | Press ESC to quit");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 40, 0xffffff, "Press 8/7 to reangle");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, 60, 0xffffff, "Press 1/2 to move through z-axis");
	game->zoom = 20;
	game->angle = 0.8;
	game->twod = 0;
	draw(game);
	mlx_key_hook(game->mlx_win, deal_key, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}