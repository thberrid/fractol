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

SRCS	= main.c 			\
			complex_plane.c \
			color.c 		\
			events_generic.c\
			fractal_sets.c 	\
			julia.c			\
			mandelbrot.c 	\
			pixel.c			\
			print.c 		\
			quit.c			\
			thread.c		\
			ship.c			\
			window.c
NAME_H	= fractol.h 		\
			keycodes.h
NAME_O	= $(SRCS:.c=.o)
FILES_O	= $(addprefix $(OBJDIR)/, $(NAME_O))
FILES_H	= $(addprefix $(INCDIR)/, $(NAME_H))

CFLAGS= -Wall -Wextra -Werror #-g3 -fsanitize=address
CPPFLAGS= -I ./$(INCDIR) -I ./libft/includes -I ./minilibx-linux
LDFLAGS = -L ./libft/ -lft -L ./minilibx-linux/ -lmlx -lm -lbsd -lX11 -lXext

LIBFT	= ./libft/libft.a
MLX		= ./minilibx-linux/libmlx.a

LINT	= norminette

all : $(NAME)

$(NAME) : $(FILES_O) $(FILES_H) $(LIBFT) $(MLX)
	$(CC) $(CPPFLAGS) -pthread -o $(NAME) $(FILES_O) $(LDFLAGS)
 
$(OBJDIR)/%.o: %.c $(FILES_H) | $(OBJDIR)
#	$(LINT) $<
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
	$(RM) -f $(FILES_O)
	make -C ./libft clean
	make -C ./minilibx-linux clean

.PHONY : fclean
fclean : clean
	make -C ./libft fclean
	$(RM) $(NAME)

.PHONY : re
re : fclean all