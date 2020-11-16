/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:58:39 by jeldora           #+#    #+#             */
/*   Updated: 2020/11/16 22:47:21 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct			s_philo
{
	pthread_t			id;
	int					index;
	size_t				life_time;
	size_t				last_eat;
	void				*data;
	size_t				print_time;
	int					count_of_eating;
}						t_philo;

typedef struct			s_data
{
	int					philo_nbr;
	int					life_time;
	int					eating_time;
	int					sleeping_time;
	int					eating_nbr;
	int					start_time;
	t_philo				**philos;
	sem_t				*forks;
	sem_t				*self_eat;
	pthread_t			id;
	int					exit_status;

	pid_t				*processes;
}						t_data;

size_t					ft_strlen(const char *s);
void					exit_with_message(char *message);
void					init(t_data *data, char **args, int argc);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
void					*pr_malloc(size_t size_of_type, size_t count);
size_t					ft_nbr_len(int n);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					timestamp(int philo_nbr, char *str, t_data *data);
size_t					get_time();
size_t					ft_strlcat(char *dst, const char *src, size_t size);

void					*live(void *data);
void					*check(void *d);

#endif
