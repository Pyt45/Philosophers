# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 09:44:47 by aaqlzim           #+#    #+#              #
#    Updated: 2021/04/12 16:48:21 by aaqlzim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

PHILO_LIB = philo_two.a

SRC = 	src/init_sem.c src/manage_philo.c src/utils_func.c \
		src/utils.c src/check_errors.c src/philo_actions.c src/philo_destroy.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

INC = include

MAIN = src/main.c

all: $(NAME)

$(NAME): $(OBJ) $(MAIN) $(INC)/philo_two.h
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