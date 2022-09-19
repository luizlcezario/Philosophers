/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:27:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 19:14:31 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int init_args(t_philosophizing *game, char **argv, int argc)
{
	game->args.num_philo = ft_atoi(argv[1]);
	game->args.t_die = ft_atoi(argv[2]);
	game->args.t_eat = ft_atoi(argv[3]);
	game->args.t_sleep = ft_atoi(argv[4]);
	game->args.t_eat_end = 1;
	if (argc == 6)
		game->args.t_eat_end = ft_atoi(argv[5]);
	else if (game->args.num_philo < 1 || game->args.t_die < 40 || game->args.t_eat
		< 40 || game->args.t_sleep < 40 || game->args.t_eat_end < 1)
	{
		printf("\033[0;31mPlease check the input numbers!\n : ERROR\033[0m\n");
		return (1);
	}
	else 
		game->args.t_eat_end = -1;
	game->args.died = 0;
	pthread_mutex_init(&game->args.lock_eat, NULL);
	pthread_mutex_init(&game->args.lock_print, NULL);
	return (0);
}

void init_philos(t_philosophizing *game)
{
	int a;

	a = -1;
	while (++a < game->args.num_philo)
	{
		game->philo[a]->args = &game->args;
		game->philo[a]->index = a + 1;
		game->philo[a]->eats = 0;
		game->philo[a]->m_forks = malloc(3 * sizeof(t_mutex *));
		game->philo[a]->m_forks[0] = game->m_forks[a];
		game->philo[a]->m_forks[1] = game->m_forks[(a + 1) % game->args.num_philo];
		if ((a + 1) % game->args.num_philo == 0)
		{
			game->philo[a]->m_forks[1] = game->philo[a]->m_forks[0];
			game->philo[a]->m_forks[0] = game->m_forks[0];
		}
		game->philo[a]->m_forks[2] = NULL;
		game->philo[a]->last_eat = 0;
	}
}

int init_philosophizing(t_philosophizing *game, char **argv, int argc)
{
	int a;

	a = init_args(game, argv, argc);
	if (a == 1)
		return (1);
	game->philo = malloc(game->args.num_philo * sizeof(t_philosophers *));
	game->m_forks = malloc(game->args.num_philo * sizeof(t_mutex *));
	a = -1;
	while (++a < game->args.num_philo)
	{
		game->philo[a] = malloc(sizeof(t_philosophers));
		game->m_forks[a] = malloc(sizeof(t_mutex));
	}
	a = -1;
	while (++a < game->args.num_philo)
		pthread_mutex_init(game->m_forks[a], NULL);
	init_philos(game);
	return (0);
}
