/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/08 19:25:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	gettime(void)
{
	time_t			now_time;
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	now_time = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	return (now_time);
}

void	save_time_start_ms(t_thread *thread)
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	pthread_mutex_lock((*thread).mutex_stop);
	thread->time_saved_ms = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	pthread_mutex_unlock((*thread).mutex_stop);
}

void	thread_loop(t_thread *thread)
{
	while (1)
	{
		thinking(thread);
		check_death(thread);
		eating(thread);
		thread->eat_count++;
		if (!(thread->eat_count_max == NOT_INIT))
		{
			if (thread->eat_count >= (size_t)thread->eat_count_max)
			{
				pthread_mutex_lock((*thread).mutex_stop);
				thread->eat_finish = TRUE;
				if (*thread->all_philos_eaten)
				{
					pthread_mutex_unlock((*thread).mutex_stop);
					pthread_exit(NULL);
				}
				pthread_mutex_unlock((*thread).mutex_stop);
			}
		}
		check_death(thread);
		sleeping(thread);
		check_death(thread);
	}
}

void	start_philo(t_thread *thread)
{
	if (thread->is_even)
	{
		thinking(thread);
		usleep(1000 * 5);
	}
}

void	*thread_main(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	pthread_mutex_lock((*thread).mutex_wait_for_threads);
	pthread_mutex_unlock((*thread).mutex_wait_for_threads);
	thread->philo_nb++;
	thread->eat_count = 0;
	if (thread->eat_count_max == NOT_INIT)
		thread->eat_count_max = INT_MAX;
	pthread_mutex_lock((*thread).mutex_stop);
	thread->last_time_eat = gettime();
	pthread_mutex_unlock((*thread).mutex_stop);
	save_time_start_ms(thread);
	if (thread->philo_count == 1)
		one_philo_hardcode(thread);
	thread_loop(thread);
	pthread_exit(NULL);
}
