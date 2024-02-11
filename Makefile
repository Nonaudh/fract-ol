CC = cc

CFLAGS = #-Wall -Werror -Wextra

SRC = src/main.c

SRC_BONUS = 

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFTDIR = lib/libft

MLXDIR = lib/mlx_linux

NAME = fracol

BONUS = 

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Ilib/mlx_linux -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	@#tput setaf 2
	$(MAKE) -sC $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo $(NAME) compiled

$(BONUS) : $(OBJ_BONUS)
	@tput setaf 2
	@$(MAKE) -sC $(LIBFTDIR) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDE) -o $(BONUS)
	@echo $(BONUS) compiled

all : $(NAME)

bonus : $(BONUS)

clean :
	@tput setaf 3
	@rm -f $(OBJ)
	@$(MAKE) -sC $(LIBFTDIR) clean
	@$(MAKE) -sC $(MLXDIR) clean
	@echo object files deleted

fclean : clean
	@tput setaf 3
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@$(MAKE) -sC $(MLXDIR) clean
	@echo executable files deleted

re: fclean all

.PHONY : all bonus clean fclean re