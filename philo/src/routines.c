/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/17 18:37:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	try_eat(t_philosophers *philo)
{
	long long	time;

	pthread_mutex_lock(philo->m_forks[0]);
	pthread_mutex_lock(philo->m_forks[1]);
	if (end_dinner(philo)) {
		return (0);
	}
	time = current_timestamp() - philo->args->start;
	printf("%lli %i has taken a fork\n", time, philo->index + 1);
	printf("%lli %i has taken a fork\n", time, philo->index + 1);
	printf("%lli %i is eating\n", time, philo->index + 1);
	philo->action = EAT;
	philo->eats++;
	mssleep(philo->args->t_eat);
	pthread_mutex_unlock(philo->m_forks[1]);
	pthread_mutex_unlock(philo->m_forks[0]);
	return(1);
}

void	sleep(t_philosophers *philo)
{
	long long time;

	time = current_timestamp() - philo->args->start;
	printf("%lli %i is sleeping\n", time, philo->index + 1);
	philo->action = SLEEP;
	mssleep(philo->args->t_sleep);
}

void	think(t_philosophers *philo) {
	long long time;

	time = current_timestamp() - philo->args->start;
	philo->action = THINK;
	printf("%lli %i is thinking\n", time, philo->index + 1);
	usleep(20);
}

int	end_dinner(t_philosophers *philo)
{
	if (philo->args->died != 0) 
		return (DIE);
	if (philo->eats == philo->args->t_eat_end)
		return (EAT);
	return (0);
}

void	*routines(void *tmp)
{
	philosophers *philo;

	philo = (t_philosophers *)tmp;
	if (philo->index % 2 != 0)
		usleep(10);
	while (end_dinner(philo))
	{
		if (!try_eat(philo) && end_dinner(philo))
			sleep(philo);
		if (end_dinner(philo) == DIE)
			break ;
		think(philo);
	}
	return(NULL);
}
