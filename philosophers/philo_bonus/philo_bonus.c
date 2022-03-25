/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:57:16 by ebassi            #+#    #+#             */
/*   Updated: 2022/03/25 14:26:56 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*start(t_philo *philo)
{
	pthread_t	thread;
	
	pthread_create(&thread, NULL, monitoring, philo);
	while (!philo->table->is_dead)
	{
		sem_wait(philo->table->forks);
		sem_wait(philo->table->writing);
		printf("[%llu] %d has taken a fork\n", get_time() - philo->table->time, \
				philo->id_philo);
		sem_post(philo->table->writing);
		sem_wait(philo->table->forks);
		sem_wait(philo->table->writing);
		printf("[%llu] %d has taken a fork\n", get_time() - philo->table->time, \
				philo->id_philo);
		sem_post(philo->table->writing);
		philo->philo_eating = 1;
		sem_wait(philo->table->writing);
		printf("[%llu] %d is eating\n", get_time() - philo->table->time, \
				philo->id_philo);
		sem_post(philo->table->writing);
		sem_wait(philo->table->is_eating);
		philo->last_meal = get_time() - philo->table->time;
		philo->nbr_meals++;
		if (philo->nbr_meals == philo->table->times_to_eat)
			philo->table->nbr_phil_finish++;
		sem_post(philo->table->is_eating);
		usleep(philo->table->eat * 1000 - 20000);
		while ((get_time() - philo->table->time) - philo->last_meal \
				< philo->table->eat)
			continue ;
		sem_post(philo->table->forks);
		sem_post(philo->table->forks);
		philo->philo_eating = 0;
		sem_wait(philo->table->writing);
		printf("[%llu] %d is sleeping\n", get_time() - philo->table->time, \
				philo->id_philo);
		sem_post(philo->table->writing);
		usleep(philo->table->sleep * 1000);
		while ((get_time() - philo->table->time) - philo->last_meal \
				< philo->table->sleep)
			continue ;
		sem_wait(philo->table->writing);
		printf("[%llu] %d is thinking\n", get_time() - philo->table->time, \
				philo->id_philo);
		sem_post(philo->table->writing);
	}
	pthread_join(thread, NULL);
	return (NULL);
}

void	medea(t_table *table)
{
	int i;
	int ret;
	i = -1;
	while (++i < table->nbr_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < table->nbr_philo)
				kill(table->phil[i]->pid, SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(table->forks);
	sem_close(table->writing);
	sem_close(table->is_eating);
	sem_unlink("sem_forks");
	sem_unlink("sem_write");
	sem_unlink("sem_eating");
}

int	main(int argc, char *argv[])
{
	t_table	*table;
	int		i;

	i = 1;
	table = 0;
	if (argc < 4 || argc > 6)
		return (ft_exit("Wrong number of arguments"));
	if (!check_arguments(&argv[1]))
		return (ft_exit("Wrong arguments"));
	table = alloc_table(table, argv);
	i = 0;
	while (i < table->nbr_philo)
	{
		table->phil[i]->pid = fork();
		if (table->phil[i]->pid < 0)
			return (ft_exit("Error while forking!\n"));
		if (!table->phil[i]->pid)
			start(table->phil[i]);
		i++;
		// usleep(100);
	}
	medea(table);
	return (1);
}