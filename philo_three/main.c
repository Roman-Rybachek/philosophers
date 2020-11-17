/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:17:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/17 03:56:43 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		wait_process(t_data *data)
{
	int	i;

	i = 0;
	waitpid(-1, NULL, WUNTRACED);
	while (i < data->philo_nbr)
	{
		kill(data->processes[i], SIGINT);
		i++;
	}
}

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
	wait_process(data);
	clean_all(data);
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
