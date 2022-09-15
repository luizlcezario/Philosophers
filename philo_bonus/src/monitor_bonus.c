/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:12:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/15 18:58:21 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void print_action(int action, t_philosophers *philo)
{
	long long time;

	sem_wait(philo->args->lock_eat);
	time = current_timestamp() - philo->args->start;
	if (action == THINK)
		printf("%lli %i is thinking\n", time, philo->index);
	else if (action == SLEEP)
		printf("%lli %i  is sleeping\n", time, philo->index);
	else if (action == EAT)
		printf("%lli %i is eating\n", time, philo->index);
	else if (action == FORK)
		printf("%lli %i has taken a fork\n", time, philo->index);
	else if (action == DIE)
		printf("%lli %i die\n", time, philo->index);
	else if (action == DINNER_OVER)
		printf("%lli every one is satisfy\n", time);
	sem_post(philo->args->lock_eat);
}

void dinner_alone(t_philosophers *philo, t_philosophizing *game)
{
	sem_wait(philo->m_forks[0]);
	print_action(FORK, philo);
	mssleep(philo->args->t_die);
	sem_post(philo->m_forks[0]);
	print_action(DIE, philo);
	exit_philo(DIE, philo, game);
}