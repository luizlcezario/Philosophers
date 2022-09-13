/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:22:49 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/12 14:49:43 by llima-ce         ###   ########.fr       */
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

void	exit_philo(int code, t_philosophers *philo, t_philosophizing *game)
{
int	i;

	sem_close(philo->args->lock_print);
	sem_close(philo->args->lock_eat);
	sem_close(*game->philo[0]->m_forks);
	i = -1;
	while (++i < game->args->num_philo)
	{
		free_ptr((void **)&game->philo[i]->m_forks);
		free_ptr((void **)&game->philo[i]);
	}
	free_ptr((void **)&game->philo);
	free_ptr((void **)&game->args);
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/forks");
	exit(code);
}

void	finish_philosophizing(t_philosophizing *game)
{
	int	i;

	sem_close(game->args->lock_print);
	sem_close(game->args->lock_eat);
	sem_close(*game->philo[0]->m_forks);
	i = -1;
	while (++i < game->args->num_philo)
	{
		free_ptr((void **)&game->philo[i]->m_forks);
		free_ptr((void **)&game->philo[i]);
	}
	free_ptr((void **)&game->philo);
	free_ptr((void **)&game->args);
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/forks");
}
