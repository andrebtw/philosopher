/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:25:50 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/16 21:53:09 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	threads_init(t_philo *philo)
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
	while (i < philo->philo_count)
	{
		if (pthread_create(&philo->threads_array[i], NULL, &thread_main, (void *)thread) != 0)
			return (free(philo->threads_array), ERR_THREAD_FAILED);
		i++;
	}
	i = 0;
	while (i < philo->philo_count)
	{
		pthread_join(philo->threads_array[i], NULL);
		i++;
	}
	free(philo->threads_array);
	return (EXIT_SUCCESS);
}
