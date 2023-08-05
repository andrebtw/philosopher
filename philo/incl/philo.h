/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:34:39 by anrodri2          #+#    #+#             */
/*   Updated: 2023/07/28 16:41:13 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* --- User headers --- */
# include "utils.h"

/* --- System libs --- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

/* --- Error codes --- */
# define ERR_MALLOC -2

/* --- Error messages --- */
# define ERR_MALLOC_MSG "Memory allocation has failed. \x1B[0m\n\x1B[33mPlease\
make sure enough memory is dedicated to the process.\n"
# define ERR_WRONG_ARGS_MSG "⛔\x1B[33m: Wrong number of arguments.\x1B[37m\n"
# define ERR_NOT_DIGIT "⛔\x1B[33m: Please make sure to \
only write digits.\x1B[37m\n"

/* --- Special codes --- */
# define NOT_INIT -15

/* --- Errors in parsing --- */
int	check_for_errors(int argc, char **argv);

#endif
