/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:14:05 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/11 10:14:05 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pu(unsigned int n, size_t *counter)
{
	char	*str;

	str = ft_ctb(n, "0123456789");
	ft_putstr(str, counter);
	free (str);
}
