/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:17:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/13 23:44:02 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		start(t_data *data)
{
	int i = 0;
	while (i < data->philo_nbr)
	{
		data->philos[i]->last_eat = get_time();
		pthread_create(&data->philos[i]->id, NULL, &live, (void*)data->philos[i]);
		usleep(30);
		i++;
	}
	
	check((void*)data);
	//pthread_create(&data->id, NULL, &check, (void*)data);
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
