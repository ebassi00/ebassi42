/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:56 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/21 18:26:06 by ebassi           ###   ########.fr       */
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
	while (!philo->table->is_dead)
	{
		// if (pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]) == 0 && pthread_mutex_lock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]) == 0)
		// {
		pthread_mutex_lock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d has taken left fork!\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		pthread_mutex_lock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d has taken right fork!\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is eating!\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_lock(&philo->table->is_eating);
		philo->last_meal = get_time() - philo->table->time;
		pthread_mutex_unlock(&philo->table->message);
		// ft_usleep(philo->table->eat);
		pthread_mutex_unlock(&philo->table->is_eating);
		usleep(philo->table->eat * 1000 - 20000);
		while ((get_time() - philo->table->time) - philo->last_meal < philo->table->eat)
			continue ;
		philo->last_meal = get_time() - philo->table->time;
		pthread_mutex_unlock(&philo->table->forks[philo->id_philo - 1]);
		pthread_mutex_unlock(&philo->table->forks[(philo->id_philo) % philo->table->nbr_philo]);
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is sleeping!\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		// ft_usleep(philo->table->sleep);
		usleep(philo->table->sleep * 1000 - 20000);
		while ((get_time() - philo->table->time) - philo->last_meal < philo->table->sleep)
			continue ;
		pthread_mutex_lock(&philo->table->message);
		printf("[%llu] %d is thinking!\n", get_time() - philo->table->time, philo->id_philo);
		pthread_mutex_unlock(&philo->table->message);
		// }
		// if ((get_time() - philo->table->time) - philo->last_meal >= philo->table->die)
		// {
		// 	pthread_mutex_lock(&philo->table->death);
		// 	pthread_mutex_lock(&philo->table->message);
		// 	printf("[%llu] %d died!\n", get_time() - philo->table->time, philo->id_philo);
		// 	// pthread_mutex_unlock(&philo->table->message);
		// 	philo->table->is_dead = 1;
		// 	// pthread_mutex_unlock(&philo->table->death);
		// 	return (NULL);
		// }
	}
	return (NULL);
}
void	ft_go(t_table *table)
{
	int i;
	
	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_create(&table->phil[i]->phil_thread, NULL, func, (void *)table->phil[i]);
		i++;
		usleep(100);
	}
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
	i = -1;
	while (++i < table->nbr_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	ft_go(table);
	while (!table->is_dead)
		continue ;
	return (1);
}