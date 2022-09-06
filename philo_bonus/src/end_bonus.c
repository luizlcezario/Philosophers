/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:22:49 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/06 18:08:58 by llima-ce         ###   ########.fr       */
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
	sem_destroy(game->args.lock_eat);
	free_ptr((void **)&game->m_forks);
	free_ptr((void **)&game->philo);
}
