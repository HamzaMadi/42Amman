#include "ft_printf.h"

void	ft_pu(unsigned int n, size_t *counter)
{
	char	*str;

	str = ft_ctb(n, "0123456789");
	ft_putstr(str, counter);
	free (str);
}
