/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/24 00:36:56 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void save_time_start_ms(t_thread *thread)
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	thread->time_saved_ms = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
}

void	thread_loop(t_thread *thread)
{
	thread->eat_count = 0;
	while (thread->eat_count < 4)
	{
		if (!thread->is_even && thread->eat_count == 0)
		eating(thread);
		sleep_philo(thread);
		thinking(thread);
		thread->eat_count++;
	}
}

void	*thread_main(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	thread->philo_nb++;
	pthread_mutex_lock((*thread).mutex_wait_for_threads);
	pthread_mutex_unlock((*thread).mutex_wait_for_threads);
	save_time_start_ms(thread);
	if (thread->is_even)
		thinking(thread);
	else
		eating(thread);
	thread_loop(thread);
	pthread_exit(NULL);
}
