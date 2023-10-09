/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 00:00:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/10 00:22:44 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	if_thread_dies(t_philo *philo, size_t i, t_thread *thread)
{
	size_t	j;

	j = 0;
	pthread_mutex_unlock(&philo->mutex_wait_for_threads);
	pthread_mutex_lock(&philo->mutex_stop);
	philo->thread_failed = TRUE;
	pthread_mutex_unlock(&philo->mutex_stop);
	while (j < i)
	{
		pthread_join(philo->threads_array[j], NULL);
		j++;
	}
	free(thread);
	free(philo->threads_array);
	mutex_destroy(philo);
}

void	check_if_philos_eaten(t_philo *philo, t_thread *thread)
{
	size_t	i;
	size_t	j;

	if (philo->is_dead)
		return ;
	pthread_mutex_lock(&philo->mutex_stop);
	i = 0;
	j = 0;
	while (i < (size_t)philo->philo_count)
	{
		if (thread[i].eat_finish)
			j++;
		i++;
	}
	if (j == (size_t)philo->philo_count)
		philo->all_philos_eaten = TRUE;
	pthread_mutex_unlock(&philo->mutex_stop);
}

void	check_philos(t_philo *philo, t_thread *thread, size_t i)
{
	time_t	ms;

	pthread_mutex_lock(&philo->mutex_stop);
	if (!thread[i].eat_finish && (thread[i].last_time_eat != \
	NOT_INIT && gettime() - thread[i].last_time_eat \
	>= thread[i].time_to_die))
	{
		ms = ms_since_start(thread[i].time_saved_ms);
		if (philo->printf_time != NOT_INIT && *thread[i].printf_time > ms)
			ms = *thread[i].printf_time;
		philo->is_dead = TRUE;
		printf("%ld %d died\n", ms, thread[i].philo_nb);
	}
	pthread_mutex_unlock(&philo->mutex_stop);
	usleep(20);
}
