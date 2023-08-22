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

void	*thread_main(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	(void)thread;
	pthread_mutex_lock((*thread).mutex_wait_for_threads);
	pthread_mutex_unlock((*thread).mutex_wait_for_threads);
	// pthread_mutex_unlock((*single).mutex);
	printf("PHILO NB: %d\n", thread->philo_nb);
	pthread_exit(NULL);
}
