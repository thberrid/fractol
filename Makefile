# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 11:04:52 by thberrid          #+#    #+#              #
#    Updated: 2021/03/29 11:04:54 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/sh
CC		= gcc
VPATH 	= sources
OBJDIR 	= obj

.SUFFIXES:
.SUFFIXES: .c .o

NAME	= fractol

DIR_O	= obj
DIR_H	= includes

NAME_C	= main.c
NAME_H	= fractol.h
NAME_O	= $(NAME_C:.s=.o)
FILES_O	= $(addprefix $(DIR_O)/, $(NAME_O))
FILES_H	= $(addprefix $(DIR_H)/, $(NAME_H))

CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
CPPFLAGS= -I ./$(DIR_H)
LDFLAGS = -L ./libft/ -lft -lm

LIBFT	= ./libft/libft.a
MLX		= ./libmlx.dylib

LINT	= norminette

all : $(NAME)

$(NAME) : $(FILES_O) $(FILES_H) $(LIBFT) $(MLX)
	$(CC) -o $(NAME) $(FILES_O) $(LDFLAGS)
 
$(DIR_O)/%.o: %.c $(FILES_H) | $(OBJDIR)
	$(LINT) $<
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $@

$(LIBFT) :
	make -C ./libft/

$(MLX) :
	make -C ./minilibx/
	cp ./minilibx/libmlx.dylib libmlx.dylib

.PHONY : clean
clean :
	$(RM) $(FILES_O)
	make -C ./libft clean
	make -C ./minilibx clean

.PHONY : fclean
fclean : clean
	make -C ./libft fclean
	make -C ./minilibx fclean
	$(RM) $(NAME)

.PHONY : re
re : fclean all