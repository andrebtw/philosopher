/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_eating.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:42:53 by anrodri2          #+#    #+#             */
/*   Updated: 2023/10/09 16:35:20 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork_even(t_thread *thread)
{
	check_death(thread);
	pthread_mutex_lock((*thread).mutex_left_fork);
	thread->left_fork_taken = TRUE;
	check_death(thread);
	philo_print_state(IS_TAKING_FORK, thread->philo_nb, \
	ms_since_start(thread->time_saved_ms), thread);
	check_death(thread);
	pthread_mutex_lock((*thread).mutex_right_fork);
	thread->right_fork_taken = TRUE;
	check_death(thread);
	philo_print_state(IS_TAKING_FORK, thread->philo_nb, \
	ms_since_start(thread->time_saved_ms), thread);
	check_death(thread);
}

void	taking_fork_odd(t_thread *thread)
{
	check_death(thread);
	pthread_mutex_lock((*thread).mutex_right_fork);
	thread->right_fork_taken = TRUE;
	check_death(thread);
	philo_print_state(IS_TAKING_FORK, thread->philo_nb, \
	ms_since_start(thread->time_saved_ms), thread);
	check_death(thread);
	pthread_mutex_lock((*thread).mutex_left_fork);
	thread->left_fork_taken = TRUE;
	check_death(thread);
	philo_print_state(IS_TAKING_FORK, thread->philo_nb, \
	ms_since_start(thread->time_saved_ms), thread);
	check_death(thread);
}

void	odd_order_eating_fork(t_thread *thread)
{
	if (thread->philo_nb % 2 == 0)
	{
		taking_fork_even(thread);
	}
	else
	{
		taking_fork_odd(thread);
	}
}

void	even_order_eating_fork(t_thread *thread)
{
	if (thread->philo_nb % 2 == 0)
	{
		taking_fork_even(thread);
	}
	else
	{
		taking_fork_odd(thread);
	}
}

void	eating(t_thread *thread)
{
	if (thread->is_count_odd)
		odd_order_eating_fork(thread);
	else
		even_order_eating_fork(thread);
	philo_print_state(IS_EATING, thread->philo_nb, \
	ms_since_start(thread->time_saved_ms), thread);
	check_death(thread);
	pthread_mutex_lock((*thread).mutex_stop);
	thread->last_time_eat = gettime();
	pthread_mutex_unlock((*thread).mutex_stop);
	check_death(thread);
	ft_usleep(1000 * thread->time_to_eat, thread);
	check_death(thread);
	pthread_mutex_unlock((*thread).mutex_right_fork);
	thread->right_fork_taken = FALSE;
	check_death(thread);
	pthread_mutex_unlock((*thread).mutex_left_fork);
	thread->left_fork_taken = FALSE;
	check_death(thread);
}
