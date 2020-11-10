/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:58:39 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/11 01:37:49 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <pthread.h>

typedef struct			s_philo
{
	/* data */
	size_t				life_time; //Время жизни

}						t_philo;

typedef struct			s_data
{
	size_t				philo_nbr;
	pthread_mutex_t		**forks; // Это вилки. Они мьютексы.
}						t_data;


/* Utils */
size_t		ft_strlen(const char *s);
void		exit_with_message(char *message);

#endif
