/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:12:59 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/26 21:36:20 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(int action, t_philosophers *philo)
{
	long long	time;

	time = current_timestamp() - philo->args->start;
	if (action == THINK)
		printf("%lli %i is thinking\n", time, philo->index + 1);
	else if (action == SLEEP)
		printf("%lli %i  is sleeping\n", time, philo->index + 1);
	else if (action == EAT)
		printf("%lli %i is eating\n", time, philo->index + 1);
	else if (action == FORK)
		printf("%lli %i has taken a fork\n", time, philo->index + 1);
	else if (action == DIE)
		printf("%lli %i die\n", time, philo->index + 1);
}

void	*monitor_routine(void *tmp)
{
	t_philosophers **monitor;
	t_args			*args;
	int				a;

	a = -1;
	monitor = (t_philosophers **)tmp;
	args = monitor[0]->args;
	while (args->died == 0 || args->num_not_satifyed != 0) {
		while (a < args->num_philo) {
			if ((current_timestamp() - args->start) - monitor[a]->last_eat > args->t_die) {
				print_action(DIE, monitor[a]);
				args->died = 1;
			}
			if (args->num_not_satifyed == 0)
				break ;
		}
	}
	return (NULL);
}