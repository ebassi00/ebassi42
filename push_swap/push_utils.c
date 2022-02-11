/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:50:07 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/10 18:15:59 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *nbr)
{
	int	i;
	
	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '-')
			i++;
		if (nbr[i] >= '0' && nbr[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	sort(char *tmp_stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (tmp_stack[i])
	{
		while (tmp_stack[j] > tmp_stack[j + 1])
		{
			tmp = tmp_stack[j];
			tmp_stack[j] = tmp_stack[j + 1];
			tmp_stack[j + 1] = tmp;
			j++;
		}
		j = 0;
		i++;
	}
}