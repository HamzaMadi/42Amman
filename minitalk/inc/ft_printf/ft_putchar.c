#include "ft_printf.h"

void	ft_putchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
