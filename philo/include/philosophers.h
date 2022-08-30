/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:28:58 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/30 18:28:38 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
// esses podem.
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;

# define USING_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DIE 0
# define THINK 1
# define EAT 2
# define SLEEP 3
# define FORK 4 
# define DINNER_OVER 5

typedef struct s_args
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_eat_end;
	long long		start;
	int				died;
	t_mutex			lock_eat;
}		t_args;

typedef struct s_philosophers {
	pthread_t		thread;
	t_mutex			**m_forks;
	t_args			*args;
	int				eats;
	int				index;
	long long		last_eat;
}	t_philosophers;

typedef struct s_philosophizing {
	t_mutex			**m_forks;
	t_philosophers	**philo;
	t_args			args;
}	t_philosophizing;

/**
 * @brief init struct to pass as arguments to the threads.
 * 
 * @param game address of the struct to init.
 * @param argv arguments of the program.
 * @param argc num	of arguments of the program.
 */
long long	current_timestamp(void);
int			init_philosophizing(t_philosophizing *game, char **argv, int argc);
void		finish_philosophizing(t_philosophizing *game);
void		start_philo(t_philosophizing *game);
void		*routines(void *game);
void		mssleep(long long mile);
void		*monitor_routine(void *tmp);
int			ft_atoi(const char *dest);
void		print_action(int action, t_philosophers *philo);
#endif // PHILOSOPHERS_H