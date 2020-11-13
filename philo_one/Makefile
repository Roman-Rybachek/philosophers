# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 00:14:30 by jeldora           #+#    #+#              #
#    Updated: 2020/11/13 20:43:31 by jeldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one


UTILS_PATH = utils

SRCS =	main.c \
		live.c \
		init.c \
		check.c \
		$(UTILS_PATH)/exit_with_message.c \
		$(UTILS_PATH)/ft_atoi.c \
		$(UTILS_PATH)/ft_itoa.c \
		$(UTILS_PATH)/ft_nbr_len.c \
		$(UTILS_PATH)/ft_putchar_fd.c \
		$(UTILS_PATH)/ft_putstr_fd.c \
		$(UTILS_PATH)/ft_strlen.c \
		$(UTILS_PATH)/get_time.c \
		$(UTILS_PATH)/protected_malloc.c \
		$(UTILS_PATH)/timestamp.c

FLAGS = -Wall -Wextra -Werror -pthread -g \
		-I. -o $(NAME)

all: $(NAME)

$(NAME): $(SRCS) header.h
	gcc $(FLAGS) $(SRCS)

#%.o: %.c
#	gcc $(FLAGS) -c $< -o $@

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all