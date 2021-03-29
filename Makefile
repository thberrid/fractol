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

INCDIR	= includes

SRCS	= main.c
NAME_H	= fractol.h
NAME_O	= $(SRCS:.c=.o)
FILES_O	= $(addprefix $(OBJDIR)/, $(NAME_O))
FILES_H	= $(addprefix $(INCDIR)/, $(NAME_H))

CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
CPPFLAGS= -I ./$(INCDIR) -I ./libft/includes
LDFLAGS = -L ./libft/ -lft -L ./minilibx-linux/ -lmlx -L -lm

LIBFT	= ./libft/libft.a
MLX		= ./minilibx-linux/libmlx.a

LINT	= norminette

all : $(NAME)

$(NAME) : $(FILES_O) $(FILES_H) $(LIBFT) $(MLX)
	$(CC) $(CPPFLAGS) -o $(NAME) $(FILES_O) $(LDFLAGS)
 
$(OBJDIR)/%.o: %.c $(FILES_H) | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $@

$(LIBFT) :
	make -C ./libft
	make -C ./libft clean

$(MLX) :
	make -C ./minilibx-linux

.PHONY : clean
clean :
	$(RM) $(FILES_O)
	make -C ./libft clean
	make -C ./minilibx clean

.PHONY : fclean
fclean : clean
	make -C ./libft fclean
	$(RM) $(NAME)

.PHONY : re
re : fclean all