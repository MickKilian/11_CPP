# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 10:28:20 by mbourgeo          #+#    #+#              #
#    Updated: 2024/12/19 10:29:27 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Project files
SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)
DEP			=	$(SRC:.cpp=.d)

# Output executable
NAME		=	PmergeMe

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files with dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Include dependencies
-include $(DEP)

# Clean up
clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
