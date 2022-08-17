/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:28:58 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/17 18:30:53 by llima-ce         ###   ########.fr       */
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

/**
 * @brief  The main function of the program.
 * 
 * pthread_mutex_t is the type a mutex that is use to synchronize threads.
 * pthread_mutex_init initializes / pthread_mutex_destroy a mutex.
 * pthread_mutex_lock / pthread_mutex_unlock : locks a mutex is to set a part of the code to be sync.
 * 
 * pthread_t is the type of a thread to use to create a thread.
 * pthread_create creates a thread.
 * pthread_join joins a thread is similar to wait is use to wait and take the result of the routine.
 * pthread_detach
 * 
 * phtread_create() is used to create a thread.
 * 
 */

# define DIE 0;
# define THINK 1;
# define EAT 2;
# define SLEEP 3;

typedef struct args
{
	int				died;
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_eat_end;
	long long		start;
}		t_args;

typedef struct philosophers {
	t_mutex			**m_forks;
	t_args			*args;
	int				eats;
	int				index;
	int				action;
	long long		last_eat;
}	t_philosophers;

typedef struct philosophizing {
	t_mutex			**m_forks;
	pthread_t		**threads;
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
void	init_philosophizing(t_philosophizing *game, char **argv, int argc);

/**
 * @brief 
 * 
 * @param game 
 */
void	start_philo(t_philosophizing *game);
void	*routines(void *game);
void	mssleep(long long mile);
long long current_timestamp();
#endif // PHILOSOPHERS_H