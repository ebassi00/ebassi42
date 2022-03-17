/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:44:57 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/17 18:53:55 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*create_philo(t_table *table, char *argv[])
{
	int	nbr_philo;
	int	i;

	i = 0;
	nbr_philo = ft_atoi(argv[0]);
	table->phil = malloc (sizeof(t_philo) * nbr_philo);
	while (i < nbr_philo)
	{
		table->phil[i]->id_philo = i + 1;
		table->phil[i]->phil_thread = malloc (sizeof(pthread_mutex_t));
		table->phil[i]->table = table;
		table->phil[i]->left_fork = 0;
		table->phil[i]->right_fork = 0;
		table->phil[i]->last_meal = 0;
		i++;
	}
	/*i = 0;
	while (i < nbr_philo)
	{
		printf("%d, %d, %d, %d\n", table->phil[i].id_philo, table->phil[i].die, table->phil[i].eat, table->phil[i].sleep);
		i++;
	}*/
	return (table);
}