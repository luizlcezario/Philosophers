/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:27:58 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/19 20:31:36 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long long current_timestamp(void)
{
	struct timeval te;
	long long milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

void mssleep(long long mile)
{
	long long microsec;

	microsec = mile * 1000;
	usleep(microsec);
}

int ft_atoi(const char *dest)
{
	int sign;
	int num;
	int a;

	a = 0;
	if (*dest == 0)
		return (0);
	while (dest[a] == ' ' || (dest[a] >= 9 && dest[a] <= 13))
		a++;
	sign = 1;
	if (dest[a] == '+' || dest[a] == '-')
	{
		if (dest[a] == '-')
			sign = -sign;
		a++;
	}
	num = 0;
	while (dest[a] <= '9' && dest[a] >= '0')
	{
		num *= 10;
		num = num + dest[a] - 48;
		a++;
	}
	return (num * sign);
}

int time(long long t)
{
	return (current_timestamp() - t);
}

void	phsleep(int rest, t_philosophers *philo, t_philosophizing *game)
{
	long long	current_time;
	long long	start_time;

	start_time = current_timestamp();
	while (time(start_time) < (long long) rest)
	{
		current_time = time(game->args->start);
		sem_wait(philo->args->lock_print);
		if ((current_time - philo->last_eat) > philo->args->t_die)
		{
			philo->args->died = DIE;
			print_action(DIE, philo);
			exit_philo(1, philo, game);
		}
		usleep(200);
		sem_post(philo->args->lock_print);
	}
}