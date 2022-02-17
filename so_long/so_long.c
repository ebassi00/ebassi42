/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:41 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/16 16:06:17 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_game *game)
{
	printf("%d\n", key);

	if (key == 53)
		exit (0);
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
	int		i;
	int		j;

	if (argc == 1 || argc > 2)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	game = mlx_init_game(argv[1]);
	printf("height: %d, width: %d\n", game->height, game->width);
	fill_matrix(game, argv[1]);
	/*i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}*/
	game->x_size = 64;
	game->y_size = 64;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->width + 1) * 64, (game->height + 1) * 64, "so_long");
	img_to_win(game);
	mlx_key_hook(game->win, deal_key, game);
	mlx_loop(game->mlx);
}