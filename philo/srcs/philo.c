/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:51 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/08 16:12:40 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo(t_philosophizing *game)
{
	pthread_t	monitor;
	int			a;

	a = -1;
	game->args.start = current_timestamp();
	while (++a < game->args.num_philo)
		pthread_create(&game->philo[a]->thread, NULL, &routines,
			(void *)game->philo[a]);
	pthread_create(&monitor, NULL, &monitor_routine, (void *)game->philo);
	a = -1;
	while (++a < game->args.num_philo)
		pthread_join(game->philo[a]->thread, NULL);
	pthread_join(monitor, NULL);
}
