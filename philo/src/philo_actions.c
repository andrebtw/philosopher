/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:13:20 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/08 15:24:07 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_thread *thread)
{
	philo_print_state(IS_THINKING, thread->philo_nb,\
	ms_since_start(thread->time_saved_ms), thread);
}

void	odd_order_eating(t_thread *thread)
{
	if (thread->philo_nb % 2 == 1)
	{
        usleep((thread->time_to_eat * 0.9) * 700);
	}
    if (thread->philo_nb % 2 == 0)
	{
        usleep((thread->time_to_eat * 0.9) * 600);
	}
	if (thread->philo_nb % 2 == 0)
	{
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_left_fork);
		thread->left_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_right_fork);
		thread->right_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
	}
	else
	{
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_right_fork);
		thread->right_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_left_fork);
		thread->left_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
	}
}

void	even_order_eating(t_thread *thread)
{
	if (thread->philo_nb % 2 == 1)
	{
        usleep((thread->time_to_eat * 0.9) * 10);
	}
	if (thread->philo_nb % 2 == 0)
	{
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_left_fork);
		thread->left_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_right_fork);
		thread->right_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
	}
	else
	{
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_right_fork);
		thread->right_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
		pthread_mutex_lock((*thread).mutex_left_fork);
		thread->left_fork_taken = TRUE;
		check_death(thread);
		philo_print_state(IS_TAKING_FORK, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
		check_death(thread);
	}
}

void	eating(t_thread *thread)
{
	if (thread->is_count_odd)
		odd_order_eating(thread);
	else
		even_order_eating(thread);
	philo_print_state(IS_EATING, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
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

void	sleeping(t_thread *thread)
{
	philo_print_state(IS_SLEEPING, thread->philo_nb, ms_since_start(thread->time_saved_ms), thread);
	ft_usleep(1000 * thread->time_to_sleep, thread);
}
