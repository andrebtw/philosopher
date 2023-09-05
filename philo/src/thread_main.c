/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/05 15:39:23 by anrodri2         ###   ########.fr       */
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
	thread->time_saved_ms = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
}

void	thread_loop(t_thread *thread)
{
	// thread->eat_count = -2;
	while (1)
	{
		// if (thread->eat_count_max == NOT_INIT)
		// 	thread->eat_count = 0;
		// else
		// 	thread->eat_count++;
		check_philo_dead(thread);
		eating(thread);
		check_philo_dead(thread);
		sleeping(thread);
		check_philo_dead(thread);
		thinking(thread);
		check_philo_dead(thread);
	}
}

void	start_philo(t_thread *thread)
{
	if (thread->is_even)
	{
		check_philo_dead(thread);
		thinking(thread);
		usleep(1000 * 5);
		check_philo_dead(thread);
	}
}

void	*thread_main(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	pthread_mutex_lock((*thread).mutex_wait_for_threads);
	pthread_mutex_unlock((*thread).mutex_wait_for_threads);
	thread->philo_nb++;
	thread->last_time_eat = gettime();
	save_time_start_ms(thread);
	start_philo(thread);
	thread_loop(thread);
	pthread_exit(NULL);
}
