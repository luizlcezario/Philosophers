/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:12:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 20:33:54 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void print_action(int action, t_philosophers *philo)
{
	long long timing;

	timing = time(philo->args->start);
	sem_wait(philo->args->lock_eat);
	if (action == THINK)
		printf("%lli %i is thinking\n", timing, philo->index);
	else if (action == SLEEP)
		printf("%lli %i  is sleeping\n", timing, philo->index);
	else if (action == EAT)
		printf("%lli %i is eating\n", timing, philo->index);
	else if (action == FORK)
		printf("%lli %i has taken a fork\n", timing, philo->index);
	else if (action == DIE)
		printf("%lli %i die\n", timing, philo->index);
	else if (action == DINNER_OVER)
		printf("%lli every one is satisfy\n", timing);
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

void	wait_forks(t_philosophers *philo, t_philosophizing *game)
{
	long	current_time;

	while (*(long *)philo->m_forks[0] < 2)
	{
		sem_wait(philo->args->lock_print);
		current_time = time(game->args->start);
		if ((current_time - philo->last_eat) > philo->args->t_die)
		{
			philo->args->died = DIE;
			print_action(DIE, philo);
			exit_philo(1, philo, game);
		}
		usleep(200);
		sem_post(philo->args->lock_print);
	}
}
