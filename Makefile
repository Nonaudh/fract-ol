CC = clang

CFLAGS = -Wall -Werror -Wextra #-g #-Ofast 

SRC = src/fractol.c src/parsing.c src/handle_keypress.c \
src/mandelbrot.c src/utils.c src/handle_mouse.c \
src/julia.c


OBJ = $(SRC:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFTDIR = lib/libft

MLXDIR = lib/mlx_linux

NAME = fractol

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Ilib/mlx_linux -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	$(MAKE) -sC $(LIBFTDIR)
	$(MAKE) -sC $(MLXDIR)
	@$(CC) $(OBJ) $(INCLUDE) -o $(NAME)
	@tput setaf 2
	@echo $(NAME) compiled

all : $(NAME)

clean :
	@rm -f $(OBJ)
	@$(MAKE) -sC $(LIBFTDIR) clean
	@$(MAKE) -sC $(MLXDIR) clean
	@echo object files deleted

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@$(MAKE) -sC $(MLXDIR) clean
	@echo executable files deleted

re: fclean all

.PHONY : all clean fclean re