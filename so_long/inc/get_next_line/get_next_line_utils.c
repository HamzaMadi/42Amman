#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	s2 = malloc(size * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	if (!s2 && !s)
		return (NULL);
	while (i < size)
	{
		s2[i] = s[i];
		i++;
	}
	s2[size] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	y;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	y = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (y < len)
	{
		str[y] = s[y + start];
		y++;
	}
	str[y] = 0;
	return (str);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*str;

	str = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		str[i] = s2[x];
		x++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
