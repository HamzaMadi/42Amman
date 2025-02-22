/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:59:46 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 12:34:20 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_numsubtring(char const *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*s)
	{
		if (*s != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*s == c)
			x = 0;
		s++;
	}
	return (count);
}

static void	*free_memory(char **s, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*substring;
	int		i;

	i = 0;
	substring = malloc((end - start + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (start < end)
	{
		substring[i] = str[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

static void	ft_initiate_vars(int *i, int *j, int *y)
{
	*i = 0;
	*j = 0;
	*y = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		j;
	int		y;

	ft_initiate_vars(&i, &j, &y);
	strings = ft_calloc((ft_numsubtring (s, c) + 1), sizeof (char *));
	if (strings == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && y < 0)
			y = i;
		else if ((s[i] == c || i == ft_strlen(s)) && y >= 0)
		{
			strings[j] = fill_word(s, y, i);
			if (!(strings[j]))
				return (free_memory(strings, j));
			y = -1;
			j++;
		}
		i++;
	}
	return (strings);
}
