# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 19:25:44 by mbourgeo          #+#    #+#              #
#    Updated: 2024/04/21 21:24:32 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

SRCS	 	= Bureaucrat.cpp main.cpp

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
