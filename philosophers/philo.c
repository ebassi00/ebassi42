/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:56 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/16 16:13:50 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_args(char *arg)
{
	if (!is_integer(arg))
		return (0);
	return (1);
}

void	*func(void *data)
{
	printf("prova\n");
	return (data);
}

int main(int argc, char *argv[])
{
	t_table	*table;
	int		i;
	int		nbr_phil;

	i = 1;
	table = malloc (sizeof(t_table));
	if (argc < 4 || argc > 5)
		return (ft_exit("Wrong number of arguments"));
	nbr_phil = ft_atoi(argv[1]);
	table = create_thread(table, &argv[1]);
	i = -1;
	while (++i < nbr_phil)
	{
		if (!(pthread_create(&table->phil[i].phil_thread, NULL, func, NULL)))
			return (ft_exit("Failed to create thread"));
	}
	return (1);
}