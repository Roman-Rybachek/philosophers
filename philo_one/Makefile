# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 00:14:30 by jeldora           #+#    #+#              #
#    Updated: 2020/11/13 01:58:20 by jeldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRCS =	main.c \
		live.c \
		init.c \
	
FLAGS = -Wall -Wextra -Werror \
		-I. -Iutils

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f

fclean: clean
	rm -f $(NAME)

re: fclean all