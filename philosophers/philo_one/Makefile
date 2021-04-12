# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 09:44:47 by aaqlzim           #+#    #+#              #
#    Updated: 2021/04/12 15:33:39 by aaqlzim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

PHILO_LIB = philo_one.a

SRC = 	src/create_philo.c src/manage_philo.c src/philo_actions.c \
		src/init_mutex.c src/utils.c src/check_errors.c src/philo_destroy.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

INC = include

MAIN = src/main.c

all: $(NAME)

$(NAME): $(OBJ) $(MAIN) $(INC)/philo_one.h
	@ar rcs $(PHILO_LIB) $(OBJ)
	@gcc $(MAIN) $(PHILO_LIB) $(OBJ) -lpthread -o $(NAME)
	@echo "SUCCESS!"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(PHILO_LIB)
	@rm -rf $(NAME)

re: fclean all