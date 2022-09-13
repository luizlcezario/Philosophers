/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:20 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/13 12:18:26 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	end_dinner(t_philosophers *philo, t_philosophizing *game)
{
	sem_wait(philo->args->lock_print);
	usleep(500);
	if (philo->args->died != 0)
		exit_philo(DIE, philo, game);
	else if (philo->eats == philo->args->t_eat_end)
		exit_philo(DINNER_OVER, philo, game);
	else if (((current_timestamp() - game->args->start) - philo->last_eat
			> game->args->t_die) && philo->eats != game->args->t_eat_end)
	{
		philo->args->died = DIE;
		print_action(DIE, philo);
		exit_philo(1, philo, game);
	}
	if ((current_timestamp() - game->args->start) - philo->last_eat
		+ philo->args->t_eat > game->args->t_die
		&& philo->eats != game->args->t_eat_end)
	{
		philo->args->died = DIE;
		print_action(DIE, philo);
		exit_philo(1, philo, game);
	}
	sem_post(philo->args->lock_print);
	return (0);
}

static int	try_eat(t_philosophers *philo, t_philosophizing *game)
{
	sem_wait(philo->m_forks[0]);
	sem_wait(philo->m_forks[1]);
	if (end_dinner(philo, game) != 0)
		return (0);
	print_action(FORK, philo);
	print_action(FORK, philo);
	print_action(EAT, philo);
	mssleep(philo->args->t_eat);
	philo->eats++;
	philo->last_eat = current_timestamp() - philo->args->start;
	sem_post(philo->m_forks[1]);
	sem_post(philo->m_forks[0]);
	return (1);
}

static void	philo_sleep(t_philosophers *philo)
{
	print_action(SLEEP, philo);
	mssleep(philo->args->t_sleep);
}

void	think(t_philosophers *philo)
{
	print_action(THINK, philo);
	usleep(200);
}

void	routines(t_philosophers	*philo, t_philosophizing *game)
{
	if (philo->args->num_philo == 1)
		dinner_alone(philo, game);
	else if ((philo->index % 2) == 0)
		usleep(1400);
	while (end_dinner(philo, game) == 0 && philo->args->num_philo != 1)
	{
		if (try_eat(philo, game) == 1 && end_dinner(philo, game) == 0)
			philo_sleep(philo);
		if (end_dinner(philo, game) != 0)
			break ;
		think(philo);
	}
	exit_philo(DIE, philo, game);
}
