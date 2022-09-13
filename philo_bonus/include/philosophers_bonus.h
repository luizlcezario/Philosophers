/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:28:58 by llima-ce          #+#    #+#             */
/*   Updated: 2022/09/12 14:56:02 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <string.h>
# include <errno.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef pthread_mutex_t	t_mutex;

# define THINK 2
# define DIE 1
# define EAT 5
# define SLEEP 3
# define FORK 4 
# define DINNER_OVER 0

typedef struct s_args
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_eat_end;
	long long		start;
	int				died;
	sem_t			*lock_eat;
	sem_t			*lock_print;
}		t_args;

typedef struct s_philosophers {
	pid_t			pid;
	sem_t			**m_forks;
	t_args			*args;
	int				eats;
	int				index;
	long long		last_eat;
}	t_philosophers;

typedef struct s_philosophizing {
	t_philosophers	**philo;
	t_args			*args;
}	t_philosophizing;

/**
 * @brief init struct to pass as arguments to the threads.
 * 
 * @param game address of the struct to init.
 * @param argv arguments of the program.
 * @param argc num	of arguments of the program.
 */
long long	current_timestamp(void);
int			init_philosophizing(t_philosophizing *game, sem_t *forks,
			char **argv, int argc);
void		finish_philosophizing(t_philosophizing *game);
void		start_philo(t_philosophizing *game);
void		routines(t_philosophers	*philo, t_philosophizing *game);
void		mssleep(long long mile);
int			ft_atoi(const char *dest);
void		print_action(int action, t_philosophers *philo);
void		dinner_alone(t_philosophers *philo, t_philosophizing *game);
void		free_ptr(void **ptr);
void		exit_philo(int exit, t_philosophers *philo, t_philosophizing *game);

#endif // PHILOSOPHERS_H