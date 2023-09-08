/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:28:36 by anrodri2          #+#    #+#             */
/*   Updated: 2023/09/08 14:45:50 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_philo *philo)
{
	size_t	i;

	i = 0;
	philo->mutex_array = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * (philo->philo_count + 1));
	if (!philo->mutex_array)
		return (ERR_MEM_ALLOC_FAILED);
	while (i < (size_t)philo->philo_count)
	{
		if (pthread_mutex_init(&philo->mutex_array[i], NULL) != 0)
			return (free(philo->mutex_array), ERR_MUTEX_FAILED);
		i++;
	}
	if (pthread_mutex_init(&philo->mutex_printf, NULL) != 0)
		return (free(philo->mutex_array), ERR_MUTEX_FAILED);
	if (pthread_mutex_init(&philo->mutex_wait_for_threads, NULL) != 0)
		return (free(philo->mutex_array), ERR_MUTEX_FAILED);
	if (pthread_mutex_init(&philo->mutex_stop, NULL) != 0)
		return (free(philo->mutex_array), ERR_MUTEX_FAILED);
	return (EXIT_SUCCESS);
}
