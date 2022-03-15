/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:18:59 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:03 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_game *game)
{
	int	len;
	int	min;

	min = 2147483647;
	len = 0;
	while (len < game->len_a)
	{
		if (game->stack_a[len] < min)
			min = game->stack_a[len];
		len++;
	}
	return (min);
}
