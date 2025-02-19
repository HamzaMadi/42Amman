NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
LIB_PATH = mlx
LIBS = -L$(LIB_PATH) -lmlx -lX11 -lXext -lm
PRINTF = inc/ft_printf/ft_ctb.c inc/ft_printf/ft_printf.c inc/ft_printf/ft_pu.c inc/ft_printf/ft_putchar.c inc/ft_printf/ft_puthex.c inc/ft_printf/ft_putnbr.c inc/ft_printf/ft_putptr.c inc/ft_printf/ft_putstr.c
GNL_FILES = inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c
SRC = main.c valid_path.c game_render.c error_free.c map_check.c initialize_map.c
OBJECTS =  $(PRINTF:.c=.o) $(GNL_FILES:.c=.o) $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
