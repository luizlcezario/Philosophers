/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:09 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 19:16:02 by llima-ce         ###   ########.fr       */
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
		printf("\033[0;31mWrong arguments\n : ERROR\033[0m\n");
	return (1);
}
