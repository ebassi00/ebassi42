/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:48:58 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/25 14:26:01 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring(void *data)
{
	t_philo	*philo;
	int		i;
	int		j;

	j = 0;
	i = 0;
	philo = (t_philo *) data;
	while (!philo->table->stop)
	{
		// usleep(100);
		// while (++i < table->nbr_philo)
		// {
			// printf("last_meal id: %d %llu\n", table->phil[i]->id_philo, table->phil[i]->last_meal);
		if (philo->table->nbr_phil_finish == philo->table->nbr_philo)
		{
			philo->table->stop = 1;
			// printf("entro\n");
			// j = -1;
			// while (++j < table->nbr_philo)
			// 	kill(table->phil[j]->pid, 15);
			// return (NULL);
		}
		if ((get_time() - philo->table->time) - philo->last_meal \
			>= philo->table->die && !philo->philo_eating)
		{
			// printf("last meal id: %d %llu\n", philo->id_philo, philo->last_meal);
			philo->table->stop = 1;
			sem_wait(philo->table->writing);
			printf("[%llu] %d died\n", get_time() - philo->table->time, \
					philo->id_philo);
			philo->table->is_dead = 1;
		}
		// }
	}
	if (philo->table->is_dead)
		exit(1);
	else
		exit(0);
	return (NULL);
}
