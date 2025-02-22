/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:14:32 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:14:32 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	address;

	if (!ptr)
	{
		ft_putstr("(nil)", counter);
	}
	else
	{
		address = (unsigned long)ptr;
		str = ft_ctb(address, "0123456789abcdef");
		ft_putstr("0x", counter);
		ft_putstr(str, counter);
		free(str);
	}
}
