/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:13:32 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:13:32 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(const char *str)
{
	size_t	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	*ft_calloc_pf(size_t nitems, size_t size)
{
	unsigned char				*array;
	size_t						i;

	i = 0;
	array = malloc(nitems * size);
	if (array == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

static size_t	ft_nod(unsigned long n, char *base)
{
	size_t			len;
	unsigned long	base_len;

	len = 1;
	base_len = ft_strlen_pf(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ctb(unsigned long n, char *base_chars)
{
	char	*str;
	int		base;
	int		num_len;

	num_len = ft_nod(n, base_chars);
	base = ft_strlen_pf(base_chars);
	str = ft_calloc_pf((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base_chars[n % base];
		n /= base;
	}
	return (str);
}
