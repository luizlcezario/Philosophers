/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:27:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/09 18:31:55 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_args(t_philosophizing *game, char **argv, int argc)
{
	game->args.num_philo = atoi(argv[1]);
	game->args.t_die = atoi(argv[2]);
	game->args.t_eat = atoi(argv[3]);
	game->args.t_sleep = atoi(argv[4]);
	if (argc == 6)
		game->args.t_eat_end = atoi(argv[5]);
	else
		game->args.t_eat_end = -1;
	if (game->args.num_philo < 1) {
		printf("Error: number of philosophers must be greater than 0\n");
		exit(1);
	}
}

void init(t_philosophizing *game) {
	int	a;

	a = 0;
	while (a < game->args.num_philo) {
		game->philo[a]->args = &game->args;
		game->philo[a]->index = a;
		game->philo[a]->eats = 0;
		game->philo[a]->m_forks = malloc(3 * sizeof(t_mutex *));
		game->philo[a]->m_forks[0] = game->m_forks[a];
		if (a == game->args.num_philo - 1)
			game->philo[a]->m_forks[1] = game->m_forks[0];
		else
			game->philo[a]->m_forks[1] = game->m_forks[a + 1];
		game->philo[a]->m_forks[2] = NULL;
		game->philo[a]->last_eat = 0;
		a++;
	}
}

void	init_philosophizing(t_philosophizing *game, char **argv, int argc)
{
	int	a;

	a = 0;
	init_args(game, argv, argc);
	game->time_start = current_timestamp();
	game->philo = malloc((game->args.num_philo) * sizeof(t_philosophers *));
	game->m_forks = malloc(game->args.num_philo * sizeof(t_mutex *));
	game->threads = malloc(game->args.num_philo * sizeof(pthread_t *));
	while (a < game->args.num_philo) {
		game->threads[a] = malloc(sizeof(pthread_t));
		game->philo[a] = malloc(sizeof(t_philosophers));
		game->m_forks[a] = malloc(sizeof(t_mutex));
		a++;
	}
	game->threads = malloc(game->args.num_philo * sizeof(pthread_t));
	init(game);
}
