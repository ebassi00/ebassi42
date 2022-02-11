/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:00 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/10 17:39:51 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	bigger;

	i = 0;
	bigger = get_bigger(stack_a);
	i = 0;
	// while (stack_a->capacity[i])   <-- PER STAMPARE LO STACK_A
	// {
	// 	printf("%d \n", stack_a->capacity[i]);
	// 	i++;
	// }
}

int		get_bigger(t_stack *stack_a)
{
	int	bigger;
	int	i;

	bigger = 0;
	i = 0;
	while (stack_a->capacity[i])
	{
		if (stack_a->capacity[i] > bigger)
			bigger = stack_a->capacity[i];
		i++;
	}
	return (bigger);
}