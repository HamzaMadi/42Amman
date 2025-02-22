/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:14:37 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:14:37 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}
