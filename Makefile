# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azgor <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 20:37:47 by azgor             #+#    #+#              #
#    Updated: 2026/04/07 20:00:54 by azgor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

%.o: %.c 
	@cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
