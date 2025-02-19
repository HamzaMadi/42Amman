#include "ft_printf.h"

void	ft_puthex(unsigned int n, size_t *counter, char *base_char)
{
	char	*str;

	str = ft_ctb(n, base_char);
	ft_putstr(str, counter);
	free (str);
}
