/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 05:34:05 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/11 13:48:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo, char **argv)
{
	philo->philo_count = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	int			ret_value;

	if (check_for_errors(argc - 1, argv))
		return (EXIT_FAILURE);
	init(&philo, argv);
	ret_value = threads_init(&philo);
	if (ret_value == ERR_MEM_ALLOC_FAILED)
		return (ERR_MEM_ALLOC_FAILED);
	else if (ret_value == ERR_THREAD_FAILED)
	{
		ft_putstr_fd(ERR_THREAD_MSG, STDERR_FILENO);
		return (ERR_THREAD_FAILED);
	}
	else if (ret_value == ERR_MUTEX_FAILED)
	{
		ft_putstr_fd(ERR_MUTEX_MSG, STDERR_FILENO);
		return (ERR_THREAD_FAILED);
	}
	return (EXIT_SUCCESS);
}
