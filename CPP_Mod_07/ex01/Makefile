# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 23:34:27 by mbourgeo          #+#    #+#              #
#    Updated: 2024/11/27 23:36:52 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex01

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

SRCS	 	= main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
