/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 00:00:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/08 19:50:54 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_philos_eaten(t_philo *philo, t_thread *thread, size_t i)
{
	if (i == 0)
	{
		if (thread[i].eat_finish)
			philo->all_philos_eaten = TRUE;
	}
	else
	{
		if (philo->all_philos_eaten && thread[i].eat_finish)
			philo->all_philos_eaten = TRUE;
		else
			philo->all_philos_eaten = FALSE;
	}
	pthread_mutex_unlock(&philo->mutex_stop);
}

void	check_philos(t_philo *philo, t_thread *thread, size_t i)
{
	pthread_mutex_lock(&philo->mutex_stop);
	if (!thread[i].eat_finish && (thread[i].last_time_eat != \
	NOT_INIT && gettime() - thread[i].last_time_eat \
	>= thread[i].time_to_die))
	{
		philo->is_dead = TRUE;
		printf("%ld %d died\n", ms_since_start(\
		thread[i].time_saved_ms), thread[i].philo_nb);
		pthread_mutex_unlock(&philo->mutex_stop);
	}
	else
	{
		check_if_philos_eaten(philo, thread, i);
	}
	usleep(20);
}
