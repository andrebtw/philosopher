/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:25:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/08 19:27:54 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	value_init(t_philo *philo, t_thread *thread, size_t i)
{
	thread->philo_nb = i;
	thread->time_to_eat = philo->time_to_eat;
	thread->time_to_sleep = philo->time_to_sleep;
	thread->time_to_die = philo->time_to_die;
	thread->eat_count = 0;
	thread->eat_count_max = philo->must_eat;
	thread->is_even = !(i % 2);
	thread->last_time_eat = NOT_INIT;
	thread->mutex_right_fork = &philo->mutex_array[i];
	if (i == 0)
		i = philo->philo_count;
	thread->mutex_left_fork = &philo->mutex_array[i - 1];
	thread->mutex_printf = &philo->mutex_printf;
	thread->mutex_wait_for_threads = &philo->mutex_wait_for_threads;
	thread->mutex_stop = &philo->mutex_stop;
	thread->is_dead = &philo->is_dead;
	thread->right_fork_taken = FALSE;
	thread->left_fork_taken = FALSE;
	thread->is_count_odd = philo->philo_count % 2;
	thread->philo_count = philo->philo_count;
	thread->eat_finish = FALSE;
}

int	threads_live_loop(t_philo *philo, t_thread *thread)
{
	philo->all_philos_eaten = FALSE;
	if (philo->philo_count == 1)
		return (EXIT_SUCCESS);
	while (philo->is_dead == FALSE && !philo->all_philos_eaten)
	{
		size_t i;

		i = 0;
		while (i < (size_t)philo->philo_count && philo->is_dead == FALSE)
		{
			pthread_mutex_lock(&philo->mutex_stop);
			if (!thread[i].eat_finish && (thread[i].last_time_eat != NOT_INIT && gettime() - thread[i].last_time_eat >= thread[i].time_to_die))
			{
				philo->is_dead = TRUE;
				pthread_mutex_unlock(&philo->mutex_stop);
				philo_print_state(IS_DEAD, thread[i].philo_nb, ms_since_start(thread[i].time_saved_ms), &thread[i]);
			}
			else
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
			usleep(1000 * 1);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int	create_threads(t_philo *philo)
{
	int			i;
	t_thread	*thread;
	int			ret_value;

	i = 0;
	ret_value = mutex_init(philo);
	if (ret_value)
		return (ret_value);
	philo->threads_array = malloc(sizeof(pthread_t) * philo->philo_count);
	if (!philo->threads_array)
		return (free(philo->mutex_array), ERR_MEM_ALLOC_FAILED);
	thread = malloc (sizeof(t_thread) * philo->philo_count);
	if (!thread)
		return (free(philo->mutex_array), free(philo->threads_array), ERR_MEM_ALLOC_FAILED);
	pthread_mutex_lock(&philo->mutex_wait_for_threads);
	while (i < philo->philo_count)
	{
		value_init(philo, &thread[i], i);
		if (pthread_create(&philo->threads_array[i], NULL, &thread_main, &thread[i]) != 0)
			return (free(philo->threads_array), ERR_THREAD_FAILED);
		i++;
	}
	pthread_mutex_unlock(&philo->mutex_wait_for_threads);
	ret_value = threads_live_loop(philo, thread);
	if (ret_value)
		return (ret_value);
	if (philo->philo_count != 1 && !philo->all_philos_eaten)
		pthread_mutex_unlock(&philo->mutex_printf);
	ret_value = threads_exit(philo);
	if (ret_value != 0)
		return (ret_value);
	ret_value = mutex_destroy(philo);
	return (ret_value);
}

int	threads_init(t_philo *philo)
{
	int	ret_value;

	ret_value = create_threads(philo);
	return (ret_value);
}
