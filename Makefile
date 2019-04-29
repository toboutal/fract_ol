# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: toboutal <toboutal@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/26 23:02:28 by toboutal     #+#   ##    ##    #+#        #
#    Updated: 2018/08/27 16:20:08 by toboutal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = fractol

CC = gcc

LIB = libft/libft.a

FLAG = -Wall -Wextra -Werror

LIBGRPH = minilibx_macos/libmlx.a  -framework OpenGL -framework Appkit

INC = fractol.h

OBJ =  julia.o mandelbrot.o burning_ship.o\
	   main.o\
	   event_mouse.o key_hook.o key_hook_2.o\

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME) $(LIBGRPH)

%.o : %.c $(INC)
	@$(CC) -c $(FLAG) $< -o $@


$(LIB):
	@make -C libft/
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*            FRACTOL          *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |* =======  COMPLETED 😎  ===== *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m \n"

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*       FRACTOL - CLEAN       *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |* =======  ALL CLEAN  🚮  ==== *| \033[33;0m"
	@echo "\033[33;34m |*                             *| \033[33;0m"
	@echo "\033[33;34m |*******************************| \033[33;0m \n"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all