/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:09 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/10 19:48:19 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_philosophizing	game;
	sem_t				*forks;
	int					i;

	forks = NULL;
	if (argc == 5 || argc == 6)
	{
		i = init_philosophizing(&game, forks, argv, argc);
		if (i == 1)
			return (1);
		start_philo(&game);
		finish_philosophizing(&game);
		return (0);
	}
	else
		perror("\033[0;31mError: wrong arguments\n\033[0;30m");
	return (1);
}
