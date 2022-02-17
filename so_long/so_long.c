/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:41 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/17 16:02:52 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_game *game)
{
	// printf("%d\n", key);

	if (key == 53)
		exit (0);
	if (key == 126)
		game->img->player_x -= 64;
	if (key == 125)
		game->img->player_x += 64;
	if (key == 123)
		game->img->player_y -= 64;
	if (key == 124)
		game->img->player_y += 64;
	mlx_clear_window(game->mlx, game->win);
	img_to_win(game);
	return (0);
}

void	handle_map(char *res, t_game *game)
{
	int	row;
	int	col;
	int	len;

	row = 0;
	col = 0;
	len = ft_strlen(res);
	if (!game->width)
		game->width = len;
	if (!game->height)
		game->height = 0;
}

int		check_ber(char *parsing_map)
{
	int	i;

	i = 0;
	while (parsing_map[i])
	{
		if (parsing_map[i] == '.')
		{
			if (parsing_map[i + 1] == 'b' && parsing_map[i + 2] \
				== 'e' && parsing_map[i + 3] == 'r' && !parsing_map[i + 4])
				return (1);
		}
		i++;
	}
	return (0);
}

t_game	*mlx_init_game(char *parsing_map)
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	game->mlx = 0;
	game->win = 0;
	game->height = 0;
	game->map = 0;
	game->width = 0;
	game->x_size = 0;
	game->y_size = 0;
	if (check_ber(parsing_map))
	{
		game->width = get_width(game, parsing_map);
		game->height = get_height(game, parsing_map);
		return (game);		
	}
	else
	{
		printf("Non valid argument / non valid map\n");
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	t_img	*img;
	int		i;
	int		j;

	if (argc == 1 || argc > 2)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	game = mlx_init_game(argv[1]);
	img = img_init();
	game->img = img;
	printf("height: %d, width: %d\n", game->height, game->width);
	fill_matrix(game, argv[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->width) * 64, (game->height) * 64, "so_long");
	img_to_win(game);
	mlx_key_hook(game->win, deal_key, game);
	mlx_loop(game->mlx);
}