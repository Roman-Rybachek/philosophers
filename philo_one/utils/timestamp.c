/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:45 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/12 19:33:32 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "header.h"
// выводит три значения

void		timestamp(int philo_nbr, char *str)
{
	ft_putstr_fd(ft_atoi(get_time()), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_atoi(philo_nbr), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}