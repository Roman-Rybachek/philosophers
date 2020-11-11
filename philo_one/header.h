/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:58:39 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 20:25:53 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_philo
{
	/* data */
	size_t				life_time; //Время жизни
	struct timeval 		las_eat;
}						t_philo;

typedef struct			s_data
{
	size_t				philo_nbr;
	size_t				life_time;
	size_t				eating_time;
	size_t				sleeping_time;
	size_t				eating_nbr;

	struct timeval 		start_time;
	pthread_mutex_t		**forks; // Это вилки. Они мьютексы.
	t_philo				*philos; // Это философы.
}						t_data;


/* Utils */
size_t		ft_strlen(const char *s);
void		exit_with_message(char *message);
int			init(t_data *data, char **args, int argc);
int			ft_atoi(const char *str);

#endif
