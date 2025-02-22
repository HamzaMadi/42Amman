/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:14:35 by hmadi             #+#    #+#             */
/*   Updated: 2024/09/22 10:37:39 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*allcote(int len);
int		length(long num);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;
	long	num;

	num = n;
	len = length(num);
	res = allcote(len);
	if (res == NULL)
		return (NULL);
	if (num < 0)
		num = -num;
	i = len - 1;
	while (num != 0)
	{
		res[i] = ((num % 10) + 48);
		num = num / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	res[len] = 0;
	return (res);
}

char	*allcote(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}

int	length(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
