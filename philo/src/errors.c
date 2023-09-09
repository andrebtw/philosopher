/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:22:52 by anrodri2          #+#    #+#             */
/*   Updated: 2023/08/07 20:06:23 by anrodri2         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (ft_isspace(string[i]))
		i++;
	if (string[i] == '-')
		return (TRUE);
	return (FALSE);
}

int	is_str_of(char *string)
{
	long long	nb;

	nb = ft_atol(string);
	if (ft_strlen(string) > 10)
		return (TRUE);
	if (nb > INT_MAX)
		return (TRUE);
	return (FALSE);
}

int	check_empty_philo(char *string)
{
	if (!atoi(string))
		return (TRUE);
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
		if (is_str_negative(argv[i]))
			return (ft_putstr_fd(ERR_NEG, STDERR_FILENO), TRUE);
		if (!is_str_digit(argv[i]))
			return (ft_putstr_fd(ERR_NOT_DIGIT, STDERR_FILENO), TRUE);
		if (is_str_of(argv[i]))
			return (ft_putstr_fd(ERR_OF, STDERR_FILENO), TRUE);
		i++;
	}
	if (check_empty_philo(argv[1]))
		return (ft_putstr_fd(ERR_NO_PHILO, STDERR_FILENO), TRUE);
	return (FALSE);
}
