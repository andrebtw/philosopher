/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:45:56 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/05 16:22:27 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_state(int state, int nb, time_t ms, t_thread *thread)
{
	pthread_mutex_lock((*thread).mutex_printf);
	if (state == IS_DEAD)
	{
		printf("%ld %d died\n", ms, nb);
	}
	else if (state == IS_EATING)
	{
		printf("%ld %d is eating\n", ms, nb);
		pthread_mutex_unlock((*thread).mutex_printf);
	}
	else if (state == IS_SLEEPING)
	{
		printf("%ld %d is sleeping\n", ms, nb);
		pthread_mutex_unlock((*thread).mutex_printf);
	}
	else if (state == IS_TAKING_FORK)
	{
		printf("%ld %d has taken a fork\n", ms, nb);
		pthread_mutex_unlock((*thread).mutex_printf);
	}
	else if (state == IS_THINKING)
	{
		printf("%ld %d is thinking\n", ms, nb);
		pthread_mutex_unlock((*thread).mutex_printf);
	}
}

void	ft_usleep(time_t useconds, t_thread *thread)
{
	struct timeval	real_time;
	time_t			time_save;
	time_t			time_update;

	gettimeofday(&real_time, NULL);
	time_save = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	time_update = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	while (time_save + useconds / 1000 > time_update)
	{
		check_philo_dead(thread);
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
