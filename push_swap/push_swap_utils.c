/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:08:33 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/11 17:05:19 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	isInteger(char *arg)
{
	long long	nbr;
	int			i;

	nbr = 0;
	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (arg[i])
	{
		nbr *= 10 + arg[i] + '0';
		i++;
	}
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

int	check_duplicates(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->len_a)
	{
		j = i + 1;
		while (j < game->len_a)
		{
			if (game->stack_a[i] == game->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}