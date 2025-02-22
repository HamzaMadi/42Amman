/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:37:10 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 12:46:21 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s);
	s2 = malloc(size * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s, size);
	s2[size] = '\0';
	return (s2);
}
