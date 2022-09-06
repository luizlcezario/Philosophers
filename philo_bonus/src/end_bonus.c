/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:22:49 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/05 17:05:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		sem_destroy(game->m_forks[i]);
		free_ptr((void **)&game->m_forks[i]);
		free_ptr((void **)&game->philo[i]->m_forks);
		free_ptr((void **)&game->philo[i]);
	}
	sem_destroy(&game->args.lock_eat);
	free_ptr((void **)&game->m_forks);
	free_ptr((void **)&game->philo);
}
