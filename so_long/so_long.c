/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:40:41 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/11 16:59:53 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_map(t_data *root, char *parsing_map)
{
	int		fd;
	char	*res;

	printf("ciao\n");
	res = 0;
	root->endian = 0;
	fd = open(parsing_map, O_RDWR);
	if (!res)
		res = get_next_line(fd);
	printf("%s\n", res);
	while (res != '\0')
	{
		res = get_next_line(fd);
		printf("%s\n", res);
	}
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

t_data	*mlx_init_root(char *parsing_map)
{
	t_data	*root;

	root = malloc (sizeof(t_data));
	root->addr = 0;
	root->bits_per_pixel = 0;
	root->endian = 0;
	root->img = 0;
	root->line_length = 0;
	root->mlx = 0;
	root->win = 0;
	if (check_ber(parsing_map))
		create_map(root, parsing_map);
	else
	{
		printf("Non valid argument / non valid map\n");
		exit (0);
	}
	return (root);
}

int	main(int argc, char *argv[])
{
	t_data	*root;


	if (argc == 1)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	root = mlx_init_root(argv[1]);
	root->mlx = mlx_init();
	root->win = mlx_new_window(root->mlx, 1920, 1080, "so_long");
	root->img = mlx_new_image(root->mlx, 1920, 1080);
	root->addr = mlx_get_data_addr(root->img, &root->bits_per_pixel, &root->line_length,
								&root->endian);
	mlx_put_image_to_window(root->mlx, root->win, root->img, 0, 0);
	mlx_loop(root->mlx);
}