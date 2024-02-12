CC = clang

CFLAGS = #-Wall -Werror -Wextra

SRC = src/main.c src/mandelbrot.c src/handle_mouse.c src/handle_keypress.c

SRC_BONUS = 

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFTDIR = lib/libft

MLXDIR = lib/mlx_linux

NAME = fractol

BONUS = 

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Ilib/mlx_linux -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	$(MAKE) -sC $(LIBFTDIR)
	$(MAKE) -sC $(MLXDIR)
	$(CC) $(OBJ) $(INCLUDE) -o $(NAME)
	@tput setaf 2
	@echo $(NAME) compiled

$(BONUS) : $(OBJ_BONUS)
	@$(MAKE) -sC $(LIBFTDIR) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDE) -o $(BONUS)
	@tput setaf 2
	@echo $(BONUS) compiled

all : $(NAME)

bonus : $(BONUS)

clean :
	@rm -f $(OBJ)
	@$(MAKE) -sC $(LIBFTDIR) clean
	@$(MAKE) -sC $(MLXDIR) clean
	@tput setaf 3
	@echo object files deleted

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@$(MAKE) -sC $(MLXDIR) clean
	@tput setaf 3
	@echo executable files deleted

re: fclean all

.PHONY : all bonus clean fclean re