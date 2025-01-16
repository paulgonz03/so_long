NAME = so_long

LIBFT_PATH = ./libft/libft.a
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
CC = cc

SRC = \
	cheakmap.c get_next_line_nuevo.c get_next_line_utils_nuevo.c main.c moves.c readmap.c\

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I/usr/include -I$(MLX_PATH)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -L$(MLX_PATH) -lX11 -lXext -lm -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
