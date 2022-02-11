/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:33:15 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/10 16:41:08 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	int	tmp;

	tmp = 0;
	tmp = stack_a->capacity[stack_a->top];
	stack_a->capacity[stack_a->top] = stack_a->capacity[stack_a->top - 1];
	stack_a->capacity[stack_a->top - 1] = tmp;
}

void	ft_sb(t_stack *stack_b)
{
	int	tmp;

	tmp = 0;
	tmp = stack_b->capacity[stack_b->top];
	stack_b->capacity[stack_b->top] = stack_b->capacity[stack_b->top - 1];
	stack_b->capacity[stack_b->top - 1] = tmp;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{	
	stack_a->top++;
	stack_a->capacity[stack_a->top] = stack_b->capacity[stack_b->top];
	stack_b->capacity[stack_b->top] = '\0';
	stack_b->top--;
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->top++;
	stack_b->capacity[stack_b->top] = stack_a->capacity[stack_a->top];
	stack_a->capacity[stack_a->top] = '\0';
	stack_a->top--;
}

void	ft_ra(t_stack *stack_a)
{
	int	tmp;
	int	i;

	i = stack_a->top;
	tmp = 0;
	while (i > 0)
	{
		tmp = stack_a->capacity[i];
		stack_a->capacity[i] = stack_a->capacity[i - 1];
		stack_a->capacity[i - 1] = tmp;
		i--;
	}
}

void	ft_rb(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = stack_b->top;
	tmp = 0;
	while (i > 0)
	{
		tmp = stack_b->capacity[i];
		stack_b->capacity[i] = stack_b->capacity[i - 1];
		stack_b->capacity[i - 1] = tmp;
		i--;
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_stack *stack_a)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = 0;
	while (i < stack_a->top + 1)
	{
		tmp = stack_a->capacity[i];
		stack_a->capacity[i] = stack_a->capacity[i - 1];
		stack_a->capacity[i - 1] = tmp;
		i++;
	}
}

void	ft_rrb(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = 0;
	while (i < stack_b->top + 1)
	{
		tmp = stack_b->capacity[i];
		stack_b->capacity[i] = stack_b->capacity[i - 1];
		stack_b->capacity[i - 1] = tmp;
		i++;
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
