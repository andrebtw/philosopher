/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:25:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/09 13:25:08 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_state(int state, int nb, int ms)
{
	if (state == IS_DEAD)
		printf("%d %d died.\n", ms, nb);
	else if (state == IS_EATING)
		printf("%d %d is eating.\n", ms, nb);
	else if (state == IS_SLEEPING)
		printf("%d %d is sleeping.\n", ms, nb);
	else if (state == IS_TAKING_FORK)
		printf("%d %d has taken a fork.\n", ms, nb);
	else if (state == IS_THINKING)
		printf("%d %d is thinking.\n", ms, nb);
}

void	*func(void *args)
{
	t_single	*single;

	(void)single;
	// pthread_mutex_lock(&single->mutex);
	// pthread_mutex_unlock(&single->mutex);
	single = args;
	pthread_exit(NULL);
}

int	threads_init(t_philo *philo, t_single single)
{
	long	i;

	i = 0;
	if (pthread_mutex_init(&single.mutex, NULL) != 0)
		return (ERR_MUTEX_FAILED);
	philo->threads = malloc(sizeof(pthread_t) * philo->philo_count + 1);
	while (i < philo->philo_count)
	{
		if (pthread_create(&philo->threads[i], NULL, &func, &single) != 0)
			return (free(philo->threads), ERR_THREAD_FAILED);
		pthread_join(philo->threads[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&single.mutex);
	return (EXIT_SUCCESS);
}
