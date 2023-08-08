/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:34:39 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/08 20:15:03 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define ERR_MALLOC_MSG "Memory allocation has failed. \x1B[0m\n\x1B[33mPlease\
make sure enough memory is dedicated to the process.\n"
# define ERR_THREAD_MSG "Thread init has failed. \x1B[0m\n\x1B[33mPlease\
make sure enough resources are available.\n"
# define ERR_WRONG_ARGS_MSG "⛔\x1B[33m: Wrong number of arguments.\x1B[37m\n"
# define ERR_NOT_DIGIT "⛔\x1B[33m: Please make sure to \
only send digits.\x1B[37m\n"
# define ERR_NEG "⛔\x1B[33m: Please make sure to \
only send positive values.\x1B[37m\n"
# define ERR_OF "⛔\x1B[33m: Please make sure to \
only send values inferior to INT_MAX.\x1B[37m\n"
# define ERR_NO_PHILO "⛔\x1B[33m: Please make sure to \
at least send 1 philo.\x1B[37m\n"

/* --- Special codes --- */
# define NOT_INIT -15
# define ERR_MEM_ALLOC_FAILED 12
# define ERR_THREAD_FAILED 13


/* --- Main struct --- */
typedef struct s_thread
{
	int	thread_id;
} t_thread ;

typedef struct s_philo
{
	pthread_t	*threads;
	t_thread	thread;
	int			philo_count;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			must_eat;	
} t_philo ;

/* --- Errors in parsing --- */
int	check_for_errors(int argc, char **argv);

#endif
