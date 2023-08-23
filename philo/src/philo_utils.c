/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:45:56 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/13 20:46:05 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_state(int state, int nb, time_t ms)
{
	if (state == IS_DEAD)
		printf("%ld %d died\n", ms, nb);
	else if (state == IS_EATING)
		printf("%ld %d is eating\n", ms, nb);
	else if (state == IS_SLEEPING)
		printf("%ld %d is sleeping\n", ms, nb);
	else if (state == IS_TAKING_FORK)
		printf("%ld %d has taken a fork\n", ms, nb);
	else if (state == IS_THINKING)
		printf("%ld %d is thinking\n", ms, nb);
}

void	ft_usleep(time_t useconds)
{
	struct timeval	real_time;
	time_t			time_save;
	time_t			time_update;

	gettimeofday(&real_time, NULL);
	time_save = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	time_update = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	while (time_save + useconds / 1000 >= time_update)
	{
		gettimeofday(&real_time, NULL);
		time_update = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
		usleep(10);
	}
}

time_t	ms_since_start(time_t time_saved_ms)
{
	struct timeval	real_time;
	time_t			ms;

	gettimeofday(&real_time, NULL);
	ms = (real_time.tv_sec * 1000 + real_time.tv_usec / 1000) - time_saved_ms;
	return (ms);
}
