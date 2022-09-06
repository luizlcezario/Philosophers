/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/05 17:12:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	sem_wait(philo->m_forks[0]);
	sem_wait(philo->m_forks[1]);
	if (end_dinner(philo))
		return (0);
	print_action(FORK, philo);
	print_action(FORK, philo);
	print_action(EAT, philo);
	mssleep(philo->args->t_eat);
	philo->eats++;
	sem_post(philo->m_forks[1]);
	sem_post(philo->m_forks[0]);
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
