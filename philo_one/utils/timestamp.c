/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:45 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/14 04:55:34 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
// выводит три значения

void		timestamp(int philo_index, char *str, t_data *data)
{
	char *s;

	pthread_mutex_lock(&data->printf_mutex);
//
	s = ft_itoa(data->philos[philo_index]->print_time); 



	ft_putstr_fd(s, 1);

	free(s);
	ft_putstr_fd(" ", 1);


	//
	s = ft_itoa(philo_index + 1);
	ft_putstr_fd(s, 1);
	free(s);
	
	ft_putstr_fd(" ", 1);

	//
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);

	pthread_mutex_unlock(&data->printf_mutex);
}
