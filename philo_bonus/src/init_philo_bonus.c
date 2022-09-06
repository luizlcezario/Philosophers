/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:27:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/05 17:03:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	init_args(t_philosophizing *game, char **argv, int argc)
{
	game->args.num_philo = ft_atoi(argv[1]);
	game->args.t_die = ft_atoi(argv[2]);
	game->args.t_eat = ft_atoi(argv[3]);
	game->args.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		game->args.t_eat_end = ft_atoi(argv[5]);
	else
		game->args.t_eat_end = -1;
	if (game->args.num_philo < 1)
	{
		printf("Error: number of philosophers must be greater than 0\n");
		return (1);
	}
	game->args.died = 0;
	sem_init(&game->args.lock_eat, 0, 1);
	return (0);
}

void	init_philos(t_philosophizing *game)
{
	int	a;

	a = -1;
	while (++a < game->args.num_philo)
	{
		game->philo[a]->args = &game->args;
		game->philo[a]->index = a + 1;
		game->philo[a]->eats = 0;
		game->philo[a]->m_forks = malloc(3 * sizeof(sem_t *));
		game->philo[a]->m_forks[0] = game->m_forks[
			(a + 1) % game->args.num_philo];
		game->philo[a]->m_forks[1] = game->m_forks[a % game->args.num_philo];
		game->philo[a]->m_forks[2] = NULL;
		game->philo[a]->last_eat = game->args.start;
	}
}

int	init_philosophizing(t_philosophizing *game, char **argv, int argc)
{
	int	a;

	a = init_args(game, argv, argc);
	if (a)
		return (1);
	game->philo = malloc(game->args.num_philo * sizeof(t_philosophers *));
	game->m_forks = malloc(game->args.num_philo * sizeof(sem_t *));
	a = -1;
	while (++a < game->args.num_philo)
	{
		game->philo[a] = malloc(sizeof(t_philosophers));
		game->m_forks[a] = malloc(sizeof(sem_t));
	}
	a = -1;
	while (++a < game->args.num_philo)
		sem_init(game->m_forks[a], 0, 1);
	game->args.start = current_timestamp();
	init_philos(game);
	return (0);
}
