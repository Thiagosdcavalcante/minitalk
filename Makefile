# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 19:12:58 by tsantana          #+#    #+#              #
#    Updated: 2024/04/05 17:57:46 by tsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES	:= server
NAMEC	:= client

CC	:= cc

CFLAGS	:= -Wextra -Wall -Werror -g3

HEADERS	:= includes/ \
	libs/libft/ \
	libs/ft_printf/

INCLUDES := libs/ft_printf/libftprintf.a \
		   libs/libft/libft.a

LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/libftprintf.a

CPPFLAGS := $(addprefix -I,$(HEADERS)) -MMD -MP
LDFLAGS := $(addprefix -L,$(dir $(INCLUDES)))
LDLIBS = -lft -ldl
LDLIBS = 

SRCS	:= srcs/client.c
SRCSS	:= srcs/server.c
		  
OBJSS	= $(SRCSS:%.c=%.o)
OBJSC	= $(SRCS:%.c=%.o)

DEPS += $(OBJSS:.o=.d)
DEPS += $(OBJSC:.o=.d)
all: $(NAMEC) $(NAMES)

$(PRINTF):
	@make -C libs/ft_printf/

$(LIBFT):
	@make -C libs/libft/

%.o: %.c
	echo "$<"
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)"

$(NAMES): $(LIBFT) $(PRINTF) $(OBJSS)
	$(CC) $(LDFLAGS) $(OBJSS) $(LDLIBS) -c $< -o $(NAMES)

$(NAMEC): $(LIBFT) $(PRINTF) $(OBJSC)
	$(CC) $(LDFLAGS) $(OBJSC) $(LDLIBS) -c $< -o $(NAMEC)

clean:
	rm -rf $(OBJSS)
	rm -rf $(OBJSC)
	rm -rf $(DEPS)
	make clean -C libs/libft
	make clean -C libs/ft_printf

fclean: clean
	rm -rf $(NAMES)
	rm -rf $(NAMEC)
	make fclean -C libs/ft_printf
	make fclean -C libs/libft

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:

-include $(DEPS)
