/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:56:14 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 10:13:55 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
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
