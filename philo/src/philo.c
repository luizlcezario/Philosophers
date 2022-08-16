/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:51 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/30 19:43:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo(t_philosophizing *game) {
	int	a;

	a = 0;
	while(a < game->args.num_philo)
	{
		pthread_create(game->threads[a], NULL, &routines, game->philo[a]);
		a++;
	}
	a = 0;
	while(a < game->args.num_philo)
	{
		pthread_join(game->threads[a], NULL);
		a++;
	}
}