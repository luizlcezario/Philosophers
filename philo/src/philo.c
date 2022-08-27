/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:51 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/26 21:49:39 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo(t_philosophizing *game)
{
	pthread_t	monitor;
	int			a;

	a = -1;
	while(++a < game->args.num_philo)
	{
		// printf("ok %d\n", game->philo[a]->index);
		pthread_create(game->threads[a], NULL, routines,
			(void *)game->philo[a]);
	}
	pthread_create(&monitor, NULL, &monitor_routine, (void *)&game->philo);
	a = -1;
	while(++a < game->args.num_philo)
		pthread_join(*game->threads[a], NULL);
	pthread_join(monitor, NULL);
	a = -1;
	while(++a < game->args.num_philo)
		pthread_mutex_destroy(game->m_forks[a]);
}