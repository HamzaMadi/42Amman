/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:14:24 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:14:24 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr((num / 10), counter);
		ft_putchar('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_putnbr((num / 10), counter);
		ft_putchar(('0' + num % 10), counter);
	}
}
