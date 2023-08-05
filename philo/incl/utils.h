/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:17:52 by anrodri2          #+#    #+#             */
/*   Updated: 2023/07/29 18:11:47 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* --- System libs --- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* --- Boolean macros --- */
# define TRUE 1
# define FALSE 0

/* --- Prototypes --- */
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
long long	ft_atol(const char *nptr);

#endif
