# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 19:12:58 by tsantana          #+#    #+#              #
#    Updated: 2024/04/09 21:08:00 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES	:= server
NAMEC	:= client

CC	:= cc

CFLAGS	:= -Wextra -Wall -Werror -g3

HEADERS	:= -I includes/ -I libs/libft/

SRCS	:= srcs/client.c
SRCSS	:= srcs/server.c

LIBFT	:= libs/libft/libft.a
	
OBJSS	= $(SRCSS:%.c=%.o)
OBJSC	= $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

all: $(NAMEC) $(NAMES)

$(NAMEC): $(LIBFT) $(OBJSC)
	$(CC) $(CFLAGS) $(OBJSC) -o $@ -Llibs/libft -lft

$(NAMES): $(LIBFT) $(OBJSS)
	$(CC) $(CFLAGS) $(OBJSS) -o $@ -Llibs/libft -lft
	
$(LIBFT):
	@make -C libs/libft/ --no-print-directory

clean:
	rm -rf $(OBJSS) $(OBJSC)
	make -C libs/libft clean

fclean: clean
	rm -rf $(NAMES) $(NAMEC)
	make -C libs/libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
