/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:10:27 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 23:49:53 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Сбор основных параметров из аргументов и проверка их корректности */
static void		base_init(t_data *data, char **args, int argc)
{
	if (!args[1] || !args[2] || !args[3] || !args[4])
		exit_with_message("Invalid arguments\n");
	data->philo_nbr = (size_t)ft_atoi(args[1]);
	data->life_time = (size_t)ft_atoi(args[2]);
	data->eating_time = (size_t)ft_atoi(args[3]);  
	data->sleeping_time = (size_t)ft_atoi(args[4]);
	if (argc == 6)
		data->eating_nbr = (size_t)ft_atoi(args[5]);
	else
		data->eating_nbr = -1;
	if (data->philo_nbr < 2 || \
		data->life_time == 0 || \
		data->eating_time == 0 || \
		data->sleeping_time == 0 || \
		data->eating_nbr == 0)
		exit_with_message("Invalid arguments\n");
}

static void		init_philo(t_data *data, int i)
{
	data->philos[i]->life_time = data->life_time;
	// Все стандартные показатели философа
}

int				init(t_data *data, char **args, int argc)
{
	int		i;

	i = 0;
	base_init(data, args, argc);	
	data->forks = (pthread_mutex_t**)pr_malloc(sizeof(pthread_mutex_t*), \
				data->philo_nbr + 1); // Память под вилки 
	data->philos = (t_philo**)pr_malloc(sizeof(t_philo*), data->philo_nbr + 1); // Память под философов
	while (i < data->philo_nbr)
	{
		data->forks[i] = (pthread_mutex_t*)pr_malloc(sizeof(pthread_mutex_t), 1);
		data->philos[i] = (t_philo*)pr_malloc(sizeof(t_philo), 1);
		i++;
	}
	data->forks[i] = NULL;
	data->philos[i] = NULL;
	// память под вилки
	// 
	/*
		выделить память для философов
		проинициализировать философов
		каждому дать указатели на мьютексы
	*/
}