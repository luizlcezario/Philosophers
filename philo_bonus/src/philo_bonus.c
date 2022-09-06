/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:51 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/05 17:16:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_philo(t_philosophizing *game)
{
	pid_t		monitor;
	int			a;

	a = -1;
	while (++a < game->args.num_philo)
	{
		monitor = fork();
		if (monitor == 0) {
			routines((void *)game->philos[a]);
		}
	}
	pthread_create(&monitor, NULL, &monitor_routine, (void *)game->philo);
	a = -1;
	while (++a < game->args.num_philo)
		pthread_join(game->philo[a]->thread, NULL);
	a = -1;
}
