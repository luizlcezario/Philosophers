/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:22:49 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/10 17:56:32 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_ptr(void **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	finish_philosophizing(t_philosophizing *game)
{
	int	i;

	i = -1;
	while (++i < game->args.num_philo)
	{
		pthread_mutex_destroy(game->m_forks[i]);
		free_ptr((void **)&game->m_forks[i]);
		free_ptr((void **)&game->philo[i]->m_forks);
		free_ptr((void **)&game->philo[i]);
	}
	pthread_mutex_destroy(&game->args.lock_eat);
	pthread_mutex_destroy(&game->args.lock_print);
	free_ptr((void **)&game->m_forks);
	free_ptr((void **)&game->philo);
}
