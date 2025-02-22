# Compiler settings
CC     := cc
CFLAGS := -Wall -Wextra -Werror

# Directories
LIBFT_D  := inc/libft
LIBFT    := $(LIBFT_D)/libft.a
PRINTF_D := inc/ft_printf

# Source files
SERVER_SRC  := server.c
CLIENT_SRC  := client.c
PRINTF_SRC  := ft_printf.c ft_ctb.c ft_pu.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c

# Object files
SERVER_OBJ  := $(SERVER_SRC:.c=.o) $(PRINTF_SRC:.c=.o)
CLIENT_OBJ  := $(CLIENT_SRC:.c=.o) $(PRINTF_SRC:.c=.o)

VPATH := $(PRINTF_D)

# Executables
SNAME := server
CNAME := client
NAME  := $(SNAME) $(CNAME)

# Compilation rules
all: $(LIBFT) $(SNAME) $(CNAME)

$(SNAME): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SNAME)

$(CNAME): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CNAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_D)

# Pattern rule for compiling `.c` files into `.o`
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning rules
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	@make -C $(LIBFT_D) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_D) fclean

re: fclean all

.PHONY: clean fclean re all
