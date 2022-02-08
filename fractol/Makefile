
# Colors
RED=$ \x1b[31m
GREEN=$ \x1b[32m
BOLD=$ \x1b[1m
END=$ \x1b[0m
CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx -Ofast
LDLIBS = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRC = main.c mandelbrot.c utiles.c hook.c julia.c julia_z3.c coloring.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(LDLIBS) -o $(NAME)
	@echo "\n$(GREEN) $(BOLD)Your programme is ready to run$(END)\n"
	

%.o : %.c fractol.h
	@$(CC) $(CFLAGS) -c $<

bonus : all

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@echo "\n$(BOLD)$(RED)Programme have been cleaned$(END)\n"

re : fclean all

.PHONY : all clean fclean re
		
