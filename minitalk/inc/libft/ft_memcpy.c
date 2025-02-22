/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:29:42 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 11:38:58 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char	*h;
	unsigned char	*y;
	size_t			i;

	h = (unsigned char *)dest_str;
	y = (unsigned char *)src_str;
	i = 0;
	if (!h && !y)
		return (NULL);
	while (i < n)
	{
		h[i] = y[i];
		i++;
	}
	return (dest_str);
}
