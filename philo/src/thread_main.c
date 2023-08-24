/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/24 18:20:37 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	save_time_start_ms(t_thread *thread)
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	thread->time_saved_ms = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
}

void	thread_loop(t_thread *thread)
{
	thread->eat_count = 0;
	while (1)
	{
		eating(thread);
		sleeping(thread);
		thinking(thread);
		thread->eat_count++;
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
	save_time_start_ms(thread);
	start_philo(thread);
	thread_loop(thread);
	pthread_exit(NULL);
}
