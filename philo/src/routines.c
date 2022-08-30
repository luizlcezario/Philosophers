/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/30 18:39:03 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	end_dinner(t_philosophers *philo)
{
	if (philo->args->died != 0)
		return (DIE);
	if (philo->eats == philo->args->t_eat_end)
		return (EAT);
	return (0);
}

static int	try_eat(t_philosophers *philo)
{
	pthread_mutex_lock(philo->m_forks[0]);
	pthread_mutex_lock(philo->m_forks[1]);
	if (end_dinner(philo))
		return (0);
	print_action(FORK, philo);
	print_action(FORK, philo);
	print_action(EAT, philo);
	philo->eats++;
	mssleep(philo->args->t_eat);
	pthread_mutex_unlock(philo->m_forks[1]);
	pthread_mutex_unlock(philo->m_forks[0]);
	return (1);
}

static void	philo_sleep(t_philosophers *philo)
{
	print_action(SLEEP, philo);
	mssleep(philo->args->t_sleep);
	philo->last_eat = current_timestamp() - philo->args->start;
}

void	think(t_philosophers *philo)
{
	print_action(THINK, philo);
	usleep(200);
}

void	*routines(void *tmp)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)tmp;
	if ((philo->index % 2) == 0)
		usleep(1400);
	while (end_dinner(philo) == 0)
	{
		if (!try_eat(philo) && end_dinner(philo))
			philo_sleep(philo);
		if (end_dinner(philo) != 0)
			break ;
		think(philo);
	}
	return (NULL);
}
