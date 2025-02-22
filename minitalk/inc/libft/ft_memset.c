/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:45:19 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 11:49:45 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*h;
	size_t			i;

	i = 0;
	h = (unsigned char *)str;
	while (i < n)
	{
		h[i] = c;
		i++;
	}
	return (str);
}
