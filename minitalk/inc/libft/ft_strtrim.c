/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:43:42 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 14:45:27 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

/*char *ft_strtrim(char const *s1, char const *set){
    size_t i;
    size_t y;
    size_t cond;
    size_t start;
    size_t end;
    char *str;
    i = 0;
    while (s1[i] != '\0' && cond == 1)
    {
        y = 0;
        cond = 0;
        while(set[y] != '\0'){
            if (set[y] == s1[i]){
            start++;
            cond = 1;
            }
            y++;
        }
        i++;
    }
    i = 0;
    while(s1[i]!= '\0'){
        end++;
        i++;
    }
    cond = 1;
        while (i < start  && cond == 1)
    {
        cond = 0;
        y = 0;
        while(set[y] != '\0'){
            if (set[y] == s1[i]){
            end--;
            cond = 1;
            }
            y++;
        }
        i--;
    }
    str = (char*)malloc(sizeof(*s1) * (end - start + 1));
    if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}*/
