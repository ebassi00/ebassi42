/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:48:58 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/24 17:59:45 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle_death(t_table *table, int i)
{
	sem_wait(table->dead);
	sem_wait(table->writing);
	printf("[%llu] %d died\n", get_time() - table->time, \
			table->phil[i]->id_philo);
	sem_close(table->forks);
	sem_close(table->dead);
	sem_close(table->writing);
	sem_close(table->is_eating);
	sem_unlink("sem_forks");
	sem_unlink("sem_write");
	sem_unlink("sem_eating");
	sem_unlink("sem_dead");
}

void	*monitoring(void *data)
{
	t_table	*table;
	int		i;
	int		j;

	j = 0;
	i = 0;
	table = (t_table *) data;
	while (!table->is_dead)
	{
		i = -1;
		while (++i < table->nbr_philo)
		{
			// printf("last_meal id: %d %llu\n", table->phil[i]->id_philo, table->phil[i]->last_meal);
			if (table->nbr_phil_finish == table->nbr_philo)
			{
				table->is_dead = 1;
				j = -1;
				while (++j < table->nbr_philo)
					kill(table->phil[j]->pid, 15);
				return (NULL);
			}
			if ((get_time() - table->time) - table->phil[i]->last_meal \
				>= table->die && !table->phil[i]->philo_eating)
			{
				printf("last meal id: %d %llu\n", table->phil[i]->id_philo, table->phil[i]->last_meal);
				handle_death(table, i);
				j = -1;
				while (++j < table->nbr_philo)
					kill(table->phil[j]->pid, 15);
				return (NULL);
			}
		}
	}
	return (NULL);
}
