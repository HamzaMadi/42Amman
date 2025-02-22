/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:11:51 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 14:15:22 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	y;
	size_t	dlen;
	size_t	slen;
	size_t	max_copy;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	y = 0;
	max_copy = size - dlen - 1;
	if (size <= dlen)
		return (size + slen);
	while (src[y] != '\0' && y < max_copy)
	{
		dest [y + dlen] = src[y];
		y++;
	}
	dest [y + dlen] = '\0';
	return (dlen + slen);
}

/*int main() {
	char src [] = "hamza";
	char dest[] = "madi";
	int i = 0;
	while (dest[i] != '\0')
		i++;
	size_t r = ft_strlcat(dest, src, 5);
	printf("%s \n", dest);
	printf("%ld", r);
	return 0;
}*/
