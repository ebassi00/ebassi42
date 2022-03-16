/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:44:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/16 16:07:21 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*create_thread(t_table *table, char *argv[])
{
	int	nbr_philo;
	int	i;

	i = 0;
	nbr_philo = ft_atoi(argv[0]);
	table->forks = nbr_philo;
	table->phil = malloc (sizeof(t_philo) * nbr_philo);
	while (i < nbr_philo)
	{
		table->phil[i].id_philo = i + 1;
		table->phil[i].die = ft_atoi(argv[1]);
		table->phil[i].eat = ft_atoi(argv[2]);
		table->phil[i].sleep = ft_atoi(argv[3]);
		i++;
	}
	i = 0;
	while (i < nbr_philo)
	{
		printf("%d, %d, %d, %d\n", table->phil[i].id_philo, table->phil[i].die, table->phil[i].eat, table->phil[i].sleep);
		i++;
	}
	return (table);
}