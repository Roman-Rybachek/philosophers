/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:45 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 02:39:36 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// выводит три значения

void		timestamp(int philo_index, char *str)
{
	char *s;

	s = ft_itoa(get_time());
	ft_putstr_fd(s, 1);
	free(s);
	ft_putstr_fd(" ", 1);
	s = ft_itoa(philo_index + 1);
	ft_putstr_fd(s, 1);
	free(s);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}