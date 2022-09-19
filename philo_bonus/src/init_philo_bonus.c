/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:27:41 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 19:10:59 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	init_args(t_philosophizing *game, char **argv, int argc)
{
	t_args	*args;

	args = malloc(1 * sizeof(t_args));
	game->args = args;
	game->args->num_philo = ft_atoi(argv[1]);
	game->args->t_die = ft_atoi(argv[2]);
	game->args->t_eat = ft_atoi(argv[3]);
	game->args->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		game->args->t_eat_end = ft_atoi(argv[5]);
	else
		game->args->t_eat_end = -1;
	if (game->args.num_philo < 1 || game->args.t_die < 40 || game->args.t_eat
		< 40 || game->args.t_sleep < 40 || game->args.t_eat_end < 1)
	{
		printf("Error: number of philosophers must be greater than 0\n");
		return (1);
	}
	game->args->died = 0;
	game->args->lock_print = sem_open("/lock_print", O_CREAT, 0777, 1);
	game->args->lock_eat = sem_open("/lock_eat", O_CREAT, 0777, 1);
	return (0);
}

void	init_philos(t_philosophizing *game, sem_t **forks)
{
	int	a;

	a = -1;
	while (++a < game->args->num_philo)
	{
		game->philo[a]->args = game->args;
		game->philo[a]->index = a + 1;
		game->philo[a]->eats = 0;
		game->philo[a]->m_forks = malloc(3 * sizeof(sem_t *));
		game->philo[a]->m_forks[0] = *forks;
		game->philo[a]->m_forks[1] = *forks;
		game->philo[a]->m_forks[2] = NULL;
		game->philo[a]->last_eat = 0;
	}
}

int	init_philosophizing(t_philosophizing *game, sem_t *forks, char **argv,
	int argc)
{
	int		a;

	sem_unlink("/forks");
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	a = init_args(game, argv, argc);
	if (a)
		return (1);
	game->philo = malloc(game->args->num_philo * sizeof(t_philosophers *));
	a = -1;
	while (++a < game->args->num_philo)
		game->philo[a] = malloc(sizeof(t_philosophers));
	a = -1;
	game->args->start = current_timestamp();
	forks = sem_open("/forks", O_CREAT, 0777, game->args->num_philo);
	init_philos(game, &forks);
	return (0);
}
