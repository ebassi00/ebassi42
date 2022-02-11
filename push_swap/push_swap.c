/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:13 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/10 18:16:36 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	struct_init(t_stack *stack, int argc)
{
	stack->top = -1;
	stack->capacity = malloc(sizeof(char) * argc + 1);
	stack->capacity[argc] = '\0';
}

void	push_swap()
{
	return ;
}

int 	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp_stack;
	t_stack	*stack_a;
	t_stack *stack_b;

	i = 1;
	j = 0;
	stack_a = malloc (sizeof(t_stack));
	stack_b = malloc (sizeof(t_stack));
	struct_init(stack_a, argc - 1);
	struct_init(stack_b, argc - 1);
	if (argc > 2)
	{
		while (argv[i])
		{
			if (ft_isnumber(argv[i]))
			{
				stack_a->top++;
				stack_a->capacity[stack_a->top] = ft_atoi(argv[i]);
			}
			else
			{
				write(1, "Error", 5);
				return (0);
			}
			i++;
		}
	}
	// if (check_if_sorted(stack_a))
	// {
	// 	return (0);
	// }
	tmp_stack = malloc (sizeof(char) * argc - 1);
	tmp_stack = stack_a->capacity;
	sort(tmp_stack);
	//resolve_algo(stack_a, stack_b);
	i = 0;
	while (tmp_stack[i])
	{
		printf("%d\n", tmp_stack[i]);
		i++;
	}
	/*i = stack_a->top;
	j = stack_b->top;
	printf("Init a and b:\n");
	while (i > -1)
	{
		printf("%d\n", stack_a->capacity[i]);
		i--;
	}
	printf("_ _\na b\n");
	ft_sa(stack_a);
	i = stack_a->top;
	printf("Exec sa:\n");
	while (i > -1)
	{
		printf("%d\n", stack_a->capacity[i]);
		i--;
	}
	printf("_ _\na b\n");
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	i = stack_a->top;
	j = stack_b->top;
	printf("Exec pb pb pb:\n");
	while (i > -1)
	{
		printf("%d %d\n", stack_a->capacity[i], stack_b->capacity[j]);
		i--;
		j--;
	}
	printf("_ _\na b\n");
	ft_ra(stack_a);
	ft_rb(stack_b);
	i = stack_a->top;
	j = stack_b->top;
	printf("Exec ra rb:\n");
	while (i > -1)
	{
		printf("%d %d\n", stack_a->capacity[i], stack_b->capacity[j]);
		i--;
		j--;
	}
	printf("_ _\na b\n");
	ft_rra(stack_a);
	ft_rrb(stack_b);
	i = stack_a->top;
	j = stack_b->top;
	printf("Exec rra rrb:\n");
	while (i > -1)
	{
		printf("%d %d\n", stack_a->capacity[i], stack_b->capacity[j]);
		i--;
		j--;
	}
	printf("_ _\na b\n");
	ft_sa(stack_a);
	i = stack_a->top;
	j = stack_b->top;
	printf("Exec sa:\n");
	while (i > -1)
	{
		printf("%d %d\n", stack_a->capacity[i], stack_b->capacity[j]);
		i--;
		j--;
	}
	printf("_ _\na b\n");
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	i = stack_a->top;
	j = stack_b->top;
	printf("Exec pa pa pa:\n");
	while (i > -1)
	{
		printf("%d %d\n", stack_a->capacity[i], stack_b->capacity[j]);
		i--;
		j--;
	}
	printf("_ _\na b\n");*/
	return (0);
}