/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:49:20 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/05 13:32:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	threads_exit(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < (size_t)philo->philo_count)
	{
		if (pthread_join(philo->threads_array[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	free(philo->threads_array);
	return (EXIT_SUCCESS);
}

int	mutex_destroy(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < (size_t)philo->philo_count)
	{
		pthread_mutex_destroy(&philo->mutex_array[i]);
		i++;
	}
	free(philo->mutex_array);
	pthread_mutex_destroy(&philo->mutex_printf);
	return (EXIT_SUCCESS);
}
