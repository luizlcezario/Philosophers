/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:27:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/30 19:43:38 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_args(t_philosophizing *game, char **argv, int argc)
{
	game.num_philo = atoi(argv[1]);
	game.t_die = atoi(argv[2]);
	game.t_eat = atoi(argv[3]);
	game.t_sleep = atoi(argv[4]);
	if (argc == 6)
		game.t_eat_end = atoi(argv[5]);
	else
		game.t_eat_end = 0;
	if (game.num_philo < 1) {
		printf("Error: number of philosophers must be greater than 0\n");
		exit(1);
	}
}

void	init_philosophizing(t_philosophizing *game, char **argv, int argc)
{
	init_args(argv, argc);
	game->table = malloc(sizeof(table_t));
	game->philo = malloc(sizeof(philosophers_t));
	game->philo->threads = malloc(game.args.num_philo * sizeof(phtread_t));
	game->table->forks = game.args.num_philo + 1;
	game->table->m_forks = malloc(game->table->forks * sizeof(pthread_mutex_t));
}
