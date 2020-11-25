# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 09:44:47 by aaqlzim           #+#    #+#              #
#    Updated: 2020/11/25 13:02:19 by aaqlzim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

PHILO_LIB = philo_one.a

SRC = 	src/create_thread.c \
		src/myturn.c \
		src/yourturn.c

FLAGS = 

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