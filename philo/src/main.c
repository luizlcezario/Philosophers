/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:09 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/30 18:39:43 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophizing	game;
	int					i;

	if (argc > 5 && argc < 7)
	{
		i = init_philosophizing(&game, argv, argc);
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
