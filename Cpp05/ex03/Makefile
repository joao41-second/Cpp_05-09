# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 10:56:28 by jperpct           #+#    #+#              #
#    Updated: 2025/07/12 11:58:35 by jperpct          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat 
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
SRCS = $(SRC:.cpp=.o)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@


all:$(NAME)

$(NAME):$(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

re:fclean all

fclean: clean
	rm -fr $(NAME)
clean: 
	rm -fr $(SRCS)


