/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:17:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/16 23:00:57 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		start(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->processes[i] = fork();
		if (data->processes[i] == 0)
		{
			live(data->philos[i]);
			exit(0);
		}
		i++;
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
