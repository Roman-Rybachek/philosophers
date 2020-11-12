/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:17:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/12 18:01:46 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		start(t_data *data)
{
	data->i = 0;
	while (data->i < data->philo_nbr)
	{
		gettimeofday(&data->philos[data->i]->last_eat, NULL);
		pthread_create(data->philos[data->i]->id, NULL, &live, data);
		data->i++;
	}
}

int				main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 6)
		exit_with_message("Invalid arguments number\n");
	init(&data, argv, argc);
	start(&data);
	return (0);
}
