NAME = so_long

MLX_PATH = ./minilibx-linux
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a
CC = cc

SRC = \
	cheakmap.c main.c moves.c readmap.c moveplyr.c floodfill.c\

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I/usr/include -I$(MLX_PATH) 

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $ 
	@make all -sC ./libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -L$(MLX_PATH) -lX11 -lXext -lm -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -sC ./libft
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -sC ./libft
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
