/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:35:10 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 12:36:43 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

/*int main() {
	char src [] = "hamza";
	char dest[] = "madi";
	int i = 0;
	char ch = 'm';
	while (dest[i] != '\0')
		i++;
		printf("%c\n", ft_tolower(ch));
// 		ft_strchr(src, ch);
		char *o = ft_strchr(src, ch);
		printf("%s \n", o);
// // 	size_t r = ft_strlcat(dest, src, 5);
// 	printf("%s \n", dest);
// 	printf("%ld", r);
	return 0;
}*/
