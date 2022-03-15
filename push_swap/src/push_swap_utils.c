/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:08:33 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/15 17:49:19 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_exit(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

long long	checks(char *arg, int i, long long nbr)
{
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			ft_exit("Error\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (arg[i])
	{
		nbr = nbr * 10 + (arg[i] - 48);
		i++;
	}
	return (nbr);
}

int	is_integer(char *arg)
{
	long long	nbr;
	int			i;
	int			sign;

	nbr = 0;
	sign = 1;
	i = 0;
	if (arg[0] == '-')
	{
		i++;
		sign = -1;
	}
	nbr = checks(arg, i, nbr);
	nbr *= sign;
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
