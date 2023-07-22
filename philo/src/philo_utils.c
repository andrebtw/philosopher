/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:45:56 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/13 20:46:05 by anrodri2         ###   ########.fr       */
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
