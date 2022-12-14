/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 20:44:22 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	end_dinner(t_philosophers *philo, t_philosophizing *game)
{
	sem_wait(philo->args->lock_print);
	if (philo->args->died != 0)
		exit_philo(DIE, philo, game);
	else if (philo->eats == philo->args->t_eat_end)
		exit_philo(DINNER_OVER, philo, game);
	else if (time(game->args->start) - philo->last_eat > game->args->t_die)
	{
		philo->args->died = DIE;
		print_action(DIE, philo);
		exit_philo(1, philo, game);
	}
	usleep(200);
	sem_post(philo->args->lock_print);
	return (0);
}

static int	try_eat(t_philosophers *philo, t_philosophizing *game)
{
	sem_wait(philo->m_forks[0]);
	sem_wait(philo->m_forks[1]);
	if (end_dinner(philo, game) != 0)
	{
		sem_wait(philo->m_forks[0]);
		sem_wait(philo->m_forks[1]);
		return (0);
	}
	print_action(FORK, philo);
	print_action(FORK, philo);
	print_action(EAT, philo);
	philo->eats++;
	philo->last_eat = current_timestamp() - philo->args->start;
	sem_wait(philo->args->lock_print);
	sem_post(philo->args->lock_print);
	phsleep(philo->args->t_eat, philo, game);
	sem_post(philo->m_forks[0]);
	sem_post(philo->m_forks[1]);
	return (1);
}

static void	philo_sleep(t_philosophers *philo, t_philosophizing *game)
{
	print_action(SLEEP, philo);
	phsleep(philo->args->t_sleep, philo, game);
}

void	think(t_philosophers *philo)
{
	print_action(THINK, philo);
	usleep(500);
}

void	routines(t_philosophers *philo, t_philosophizing *game)
{
	if (philo->args->num_philo == 1)
		dinner_alone(philo, game);
	else if ((philo->index % 2) == 0)
		usleep(1400);
	while (end_dinner(philo, game) == 0 && philo->args->num_philo != 1)
	{
		if (try_eat(philo, game) == 1 && end_dinner(philo, game) == 0)
			philo_sleep(philo, game);
		if (end_dinner(philo, game) != 0)
			break ;
		think(philo);
		wait_forks(philo, game);
	}
	exit_philo(DIE, philo, game);
}
