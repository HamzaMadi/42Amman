#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_ctb(unsigned long n, char *base_chars);
int		ft_printf(char const *str, ...);
void	ft_pu(unsigned int n, size_t *counter);
void	ft_putchar(char c, size_t *counter);
void	ft_puthex(unsigned int n, size_t *counter, char *base_char);
void	ft_putnbr(int num, size_t *counter);
void	ft_putptr(void *ptr, size_t *counter);
void	ft_putstr(char *str, size_t *counter);

#endif
