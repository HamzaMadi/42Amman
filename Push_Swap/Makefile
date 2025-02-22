NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra

SRCS        = main.c handle_errors.c init_a_to_b.c init_b_to_a.c \
             push.c rev_rotate.c rotate.c sort_stacks.c sort_mini.c \
             split.c stack_init.c stack_utils.c swap.c ft_isdigit.c
SRCSPRINTF  = inc/ft_printf/ft_printf.c \
             inc/ft_printf/ft_putchar.c \
             inc/ft_printf/ft_putstr.c \
             inc/ft_printf/ft_putnbr.c \
             inc/ft_printf/ft_puthex.c \
             inc/ft_printf/ft_putptr.c \
			 inc/ft_printf/ft_pu.c \
			 inc/ft_printf/ft_ctb.c

OBJS        = $(SRCS:.c=.o) $(SRCSPRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
