/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:09 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/26 21:41:13 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosophizing	game;

	if(argc > 5 && argc < 7)
	{
		init_philosophizing(&game, argv, argc);
		start_philo(&game);
		return (0);
	}
	else
		perror("\033[0;31mError: wrong arguments\n\033[0;30m");
	return (1);
}
