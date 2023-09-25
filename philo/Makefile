# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 < anrodri2@student.42lyon.fr >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 05:39:33 by anrodri2          #+#    #+#              #
#    Updated: 2023/09/06 18:20:39 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### --- FINAL COMPILATION FILE --- ###
NAME = philo

#### DIRECTORIES ####
SRC_DIR = src/

OBJS_DIR = ./objs/

INC_DIR = incl/

#### --- SOURCE FILES --- ####
SRCS = 	main.c \
		thread_init.c \
		thread_exit.c \
		philo_actions.c \
		philo_actions_eating.c \
		mutex_init.c \
		errors.c \
		thread_main.c \
		philo_utils.c \
		utils/ft_putstr_fd.c \
		utils/ft_atoi.c \
		utils/ft_atol.c \
		utils/ft_isdigit.c \
		utils/ft_strlen.c \
		utils/ft_isspace.c \


#### --- OBJS --- ####
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

#### --- FLAGS --- ####
CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread

RM = rm -rf

DFLAGS = -MMD -MP

IFLAGS = -I $(INC_DIR)

#### --- RULES --- ####
all:		$(NAME)

-include	$(DEPS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $@

$(OBJS_DIR)%.o:		$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS_DIR) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:	fclean $(NAME)

#### --- PHONY --- ####
.PHONY: all clean fclean re
