/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:10:27 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/16 22:48:21 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		base_init(t_data *data, char **args, int argc)
{
	if (!*args[1] || !*args[2] || !*args[3] || !*args[4])
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

static void		init_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philos[i]->life_time = data->life_time;
		data->philos[i]->index = i;
		data->philos[i]->data = data;
		data->philos[i]->count_of_eating = 0;
		i++;
	}
}

void			init(t_data *data, char **args, int argc)
{
	int				i;

	i = 0;
	data->exit_status = 0;
	base_init(data, args, argc);
	data->philos = (t_philo**)pr_malloc(sizeof(t_philo*), data->philo_nbr);
	sem_unlink("Forks");
	sem_unlink("Self_eat");
	if ((data->forks = sem_open("Forks", O_CREAT, 0777, data->philo_nbr)) \
		== SEM_FAILED)
		exit(-1);
	if ((data->self_eat = sem_open("Self_eat", O_CREAT, 0777, \
		data->philo_nbr / 2)) == SEM_FAILED)
		exit(-1);
	while (i < data->philo_nbr)
	{
		data->philos[i] = (t_philo*)pr_malloc(sizeof(t_philo), 1);
		i++;
	}
	init_philos(data);
	data->processes = (pid_t*)pr_malloc(sizeof(pid_t), data->philo_nbr);
	data->start_time = get_time();
}
