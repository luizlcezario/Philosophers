/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:12:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/30 18:52:56 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(int action, t_philosophers *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->args->lock_eat);
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
	pthread_mutex_unlock(&philo->args->lock_eat);
}

static int	verify_monitor(t_philosophers **monitor, t_args *args)
{
	int	num_not_satifyed;
	int	a;

	a = 0;
	num_not_satifyed = args->num_philo;
	while (args->died == 0 && num_not_satifyed != 0)
	{
		if (a < 0 || a > args->num_philo - 1)
		{
			usleep(1000);
			num_not_satifyed = args->num_philo;
			a = 0;
		}
		if ((current_timestamp() - args->start) - monitor[a]->last_eat
			> args->t_die)
		{
			print_action(DIE, monitor[a]);
			args->died = 1;
		}
		if (monitor[a]->eats == args->t_eat_end)
			num_not_satifyed--;
		a++;
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
