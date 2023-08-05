# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 05:39:33 by anrodri2          #+#    #+#              #
#    Updated: 2023/07/12 15:17:22 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### --- FINAL COMPILATION FILE --- ###
NAME = philo

#### DIRECTORIES ####
SRC_DIR = src/

OBJS_DIR = ./objs/

INC_DIR = incl/

#### --- SOURCE FILES --- ####

SRCS = 	main.c\
		utils/ft_putstr_fd.c\

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

#### --- SYSTEM --- ####
CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g3

DFLAGS = -MMD -MP

IFLAGS = -I $(INC_DIR)

#### RULES ####
all:		$(NAME)

-include	$(DEPS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $@

# $(LIBFT):	FORCE
# 			$(MAKE) all -j -C $(LIB_DIR)

FORCE:

$(OBJS_DIR)%.o:		$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

clean:
			$(MAKE) clean -C
			$(RM) $(OBJS_DIR) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re FORCE