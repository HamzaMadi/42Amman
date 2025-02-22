/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:14:19 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:14:19 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, size_t *counter, char *base_char)
{
	char	*str;

	str = ft_ctb(n, base_char);
	ft_putstr(str, counter);
	free (str);
}
