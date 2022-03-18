/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:56 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/18 18:19:59 by ebassi           ###   ########.fr       */
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
	t_philo		*philo;

	philo = (t_philo *) data;
	while (philo->table->is_dead)
	{
		if (pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]) == 0 && pthread_mutex_lock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]) == 0)
		{
			printf("[%llu] %d has taken left fork!\n", get_time() - philo->table->time, philo->id_philo);
			printf("[%llu] %d has taken right fork!\n", get_time() - philo->table->time, philo->id_philo);
			printf("[%llu] %d is eating!\n", get_time() - philo->table->time, philo->id_philo);
			usleep(philo->table->eat * 1000 - 20000);
			while (get_time() - (uint64_t)philo->last_meal - philo->table->time < philo->table->eat)
				continue ;
			philo->last_meal = get_time() - philo->table->time;
			pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
			pthread_mutex_unlock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]);
			printf("[%llu] %d is sleeping!\n", get_time() - philo->table->time, philo->id_philo);
			usleep(philo->table->sleep * 1000 - 20000);
			while (get_time() - philo->last_meal - philo->table->time < philo->table->sleep)
				continue ;
			printf("[%llu] %d is thinking!\n", get_time() - philo->table->time, philo->id_philo);
		}
		if ((get_time() - philo->table->time) - (uint64_t)philo->last_meal > philo->table->die)
		{
			pthread_mutex_lock(&philo->table->death);
			printf("[%llu] %d is dead!\n", get_time() - philo->table->time, philo->id_philo);
			philo->table->is_dead = 0;
			pthread_mutex_unlock(&philo->table->death);
		}
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_table	*table;
	int		i;

	i = 1;
	table = 0;
	if (argc < 4 || argc > 5)
		return (ft_exit("Wrong number of arguments"));
	// if (!check_arguments(&argv[1]))
	// 	return (ft_exit("Wrong arguments"));
	table = alloc_table(table, argv);
	pthread_mutex_init(&table->death, NULL);
	i = -1;
	while (++i < table->nbr_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	while (table->is_dead)
	{
		i = -1;
		while (++i < table->nbr_philo)
		{
			pthread_create(&table->phil[i]->phil_thread, NULL, func, table->phil[i]);
			usleep(100);
		}
	}
	return (1);
}