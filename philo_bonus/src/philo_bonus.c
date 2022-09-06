/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:39:51 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/06 17:32:56 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	wait_process(t_philosophizing *game)
{
	int	i;
	int	exit_code;

	exit_code = 0;
	i = -1;
	while (++i < game->args.num_philo && exit_code == 0)
	{
		waitpid(-1, &exit_code, 0);
		exit_code = WEXITSTATUS(exit_code);
	}
	if (exit_code)
	{
		i = -1;
		while (++i < game->args.num_philo)
			kill(game->philo[i]->pid, SIGKILL);
	}
	return (exit_code);
}

void	start_philo(t_philosophizing *game)
{
	int			a;

	a = -1;
	while (++a < game->args.num_philo)
	{
		game->philo[a]->pid = fork();
		if (game->philo[a]->pid == 0)
			routines((void *)game->philo[a]);
	}
	a = wait_process(game);
	if (a == 0)
		print_action(DINNER_OVER, game->philo[a]);
}
