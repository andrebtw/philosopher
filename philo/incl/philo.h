/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:34:39 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/08 14:45:46 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* --- Define --- */
#ifndef PHILO_H
# define PHILO_H

/* --- Constants --- */
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* --- User headers --- */
# include "utils.h"

/* --- System libs --- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* --- Boolean macros --- */
# define TRUE 1
# define FALSE 0

/* --- Colours --- */
# define KNORMAL "\x1B[0m"
# define KRED "\x1B[31m"
# define KGREEN "\x1B[32m"
# define KYELLOW "\x1B[33m"
# define KBLUE "\x1B[34m"
# define KWHITE "\x1B[37m"

/* --- Error messages --- */
# define ERR_MALLOC_MSG "Memory allocation has failed. \x1B[0m\n\x1B[33m Please\
 make sure enough memory is dedicated to the process.\n\x1B[0m"
# define ERR_THREAD_MSG "Thread init has failed. \x1B[0m\n\x1B[33mPlease\
 make sure enough resources are available.\n\x1B[0m"
# define ERR_MUTEX_MSG "Mutex init has failed. \x1B[0m\n\x1B[33mPlease\
 make sure enough resources are available.\n\x1B[0m"
# define ERR_WRONG_ARGS_MSG "⛔\x1B[33m: Wrong number of arguments.\x1B[37m\n"
# define ERR_NOT_DIGIT "⛔\x1B[33m: Please make sure to \
only send digits.\x1B[37m\n"
# define ERR_NEG "⛔\x1B[33m: Please make sure to \
only send positive values.\x1B[37m\n"
# define ERR_NOT_ENOUGH_TIMES "⛔\x1B[33m: Please make sure to \
at least make the philos eat once.\x1B[37m\n"
# define ERR_OF "⛔\x1B[33m: Please make sure to \
only send values inferior to INT_MAX.\x1B[37m\n"
# define ERR_NO_PHILO "⛔\x1B[33m: Please make sure to \
at least send 1 philo.\x1B[37m\n"

/* --- Special codes --- */
# define NOT_INIT -15
# define ERR_MEM_ALLOC_FAILED 12
# define ERR_THREAD_FAILED 13
# define ERR_MUTEX_FAILED 14

/* --- Philo states --- */
# define IS_EATING -2000
# define IS_SLEEPING -3000
# define IS_THINKING -4000
# define IS_DEAD -5000
# define IS_TAKING_FORK -6000

/* --- Time struct --- */
typedef struct timeval	t_timeval;

/* --- Main struct --- */
typedef struct s_philo
{
	pthread_t		*threads_array;
	pthread_mutex_t	*mutex_array;
	pthread_mutex_t	mutex_wait_for_threads;
	pthread_mutex_t	mutex_stop;
	int				fork_count;
	int				philo_count;
	int				must_eat;
	int				eat_count_max;
	time_t			time_to_eat;
	time_t			time_to_die;
	time_t			time_to_sleep;
	int				is_dead;
	int				all_philos_eaten;
	time_t			printf_time;
	int				thread_failed;
}	t_philo;

typedef struct s_thread
{
	pthread_mutex_t	*mutex_left_fork;
	pthread_mutex_t	*mutex_right_fork;
	pthread_mutex_t	*mutex_wait_for_threads;
	pthread_mutex_t	*mutex_stop;
	int				philo_nb;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			time_to_die;
	int				eat_count_max;
	size_t			eat_count;
	int				is_even;
	int				right_fork_taken;
	int				left_fork_taken;
	time_t			time_saved_ms;
	time_t			last_time_eat;
	int				*is_dead;
	int				is_count_odd;
	int				philo_count;
	int				eat_finish;
	int				*all_philos_eaten;
	time_t			*printf_time;
	int				*thread_failed;
}	t_thread;

/* --- Errors in parsing --- */
int		check_for_errors(int argc, char **argv);

/* --- Threads creation --- */
void	*thread_main(void *args);
int		threads_exit(t_philo *philo);
int		threads_init(t_philo *philo);
void	check_philos(t_philo *philo, t_thread *thread, size_t i);
void	check_if_philos_eaten(t_philo *philo, t_thread *thread);

/* --- Threads main loop --- */
void	if_thread_dies(t_philo *philo, size_t i, t_thread *thread);

/* --- Mutex --- */
int		mutex_init(t_philo *philo);
int		mutex_destroy(t_philo *philo);

/* --- Philo actions --- */
void	thinking(t_thread *thread);
void	eating(t_thread *thread);
void	sleeping(t_thread *thread);

/* --- Philo utils --- */
void	philo_print_state(int state, int nb, time_t ms, t_thread *thread);
void	ft_usleep(time_t useconds, t_thread *thread);
time_t	ms_since_start(time_t time_saved_ms);
time_t	gettime(void);
void	check_death(t_thread *thread);
void	one_philo_hardcode(t_thread *thread);

#endif
