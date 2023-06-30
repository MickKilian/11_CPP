# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 00:51:30 by mbourgeo          #+#    #+#              #
#    Updated: 2023/04/30 00:55:49 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

DFLAGS		= -MMD -MF

SRCS	 	= Harl.cpp main.cpp

OBJS		= $(SRCS:.cpp=.o)

DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)
%.o: %.cpp
	$(CC) $(CFLAGS) $(DFLAGS) $*.d -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
