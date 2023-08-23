/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:46:13 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/13 20:29:11 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_first(t_thread *thread)
{
	
	philo_print_state(IS_EATING, thread->philo_nb, ms_since_start(thread->time_saved_ms));
}

void save_time_start_ms(t_thread *thread)
{
	struct timeval	real_time;

	gettimeofday(&real_time, NULL);
	thread->time_saved_ms = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
}

void	*thread_main(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	pthread_mutex_lock((*thread).mutex_wait_for_threads);
	pthread_mutex_unlock((*thread).mutex_wait_for_threads);
	save_time_start_ms(thread);
	if (thread->is_even)
	{
		eat_first(thread);
	}
	pthread_exit(NULL);
}
