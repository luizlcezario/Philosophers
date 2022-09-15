/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:12:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/15 02:31:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(int action, t_philosophers *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->args->lock_print);
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
	pthread_mutex_unlock(&philo->args->lock_print);
}

static int	verify_death(t_philosophers **monitor, t_args *args)
{
	int	a;

	a = 0;
	while (a < monitor[0]->args->num_philo)
	{
		pthread_mutex_lock(&monitor[0]->args->lock_eat);
		if (((current_timestamp() - args->start) - monitor[a]->last_eat
				> args->t_die) && monitor[a]->eats != args->t_eat_end)
		{
			print_action(DIE, monitor[a]);
			args->died = 1;
			pthread_mutex_unlock(&monitor[0]->args->lock_eat);
			return (-1);
		}
		pthread_mutex_unlock(&monitor[0]->args->lock_eat);
		a++;
	}
	return (0);
}

static int	verify_monitor(t_philosophers **monitor, t_args *args)
{
	int	a;
	int	num_not_satifyed;

	num_not_satifyed = monitor[0]->args->num_philo;
	while (args->died == 0 && num_not_satifyed != 0)
	{
		usleep(300);
		a = verify_death(monitor, args);
		if (a == -1)
			return (-1);
		num_not_satifyed = args->num_philo;
		while (a < monitor[0]->args->num_philo)
		{
			pthread_mutex_lock(&args->lock_eat);
			if (monitor[a]->eats == args->t_eat_end)
				num_not_satifyed--;
			pthread_mutex_unlock(&args->lock_eat);
			a++;
		}
	}
	return (num_not_satifyed);
}

void	*monitor_routine(void *tmp)
{
	t_philosophers	**monitor;
	int				i;

	monitor = (t_philosophers **)tmp;
	i = verify_monitor(monitor, monitor[0]->args);
	if (i == 0)
		print_action(DINNER_OVER, monitor[0]);
	return (NULL);
}
