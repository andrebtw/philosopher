/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:22:52 by anrodri2          #+#    #+#             */
/*   Updated: 2023/07/29 18:16:29 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_str_digit(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_str_negative(char *string)
{
	if (ft_atol(string) < 0)
	{
		
	}
	return (FALSE);
}

int	check_for_errors(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc != 4 && argc != 5)
		return (ft_putstr_fd(ERR_WRONG_ARGS_MSG, STDERR_FILENO), TRUE);
	while (argv[i])
	{
		if (!is_str_digit(argv[i]))
			return (ft_putstr_fd(ERR_NOT_DIGIT, STDERR_FILENO), TRUE);
		i++;
	}
	return (FALSE);
}
