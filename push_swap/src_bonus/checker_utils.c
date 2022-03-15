/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:08:12 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 18:23:48 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all2(t_game *game)
{
	free(game->stack_a);
	free(game->stack_b);
	free(game);
}

void	free_nbrs(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}
