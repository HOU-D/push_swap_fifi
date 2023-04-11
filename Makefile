# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:04:34 by hoakoumi          #+#    #+#              #
#    Updated: 2023/04/11 00:37:16 by hoakoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
NAME = push_swap
SRCS =   main.c  outils1.c sort.c libft.c libft1.c instructions.c check_sorting.c list.c liste_to_table.c  push_to_a.c  push_to_b.c   sort_100.c
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g


CC = cc
RM = rm -rf
all: $(NAME)

OBJ = $(SRCS:%.c=%.o)
OBJB = $(SRCSB:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)   $(SRCS) -o $(NAME)
SRCSB = push_swap_bonus.c  sort.c libft.c libft1.c insb.c check_sorting.c list.c liste_to_table.c  push_to_a.c  push_to_b.c  sort_100.c  get_next_line.c
bonus : $(CHECKER)

$(CHECKER): $(OBJB)
	$(CC) $(CFLAGS) $(SRCSB) -o $(CHECKER)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all
