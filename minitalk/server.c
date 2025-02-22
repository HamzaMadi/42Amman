/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:09:30 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/22 11:08:54 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	message_len(pid_t signal)
{
	static size_t		bit;
	static unsigned int	len;
	unsigned int		temp;

	temp = 0;
	if (signal == SIGUSR1)
		len |= (1 << bit);
	else if (signal == SIGUSR2)
		len |= (0 << bit);
	bit++;
	if (bit == 32)
	{
		temp = len;
		bit = 0;
		len = 0;
		return (temp);
	}
	return (0);
}

void	print_message(pid_t signal, char **message, size_t *b,
		unsigned int *len)
{
	static char		ch;
	static size_t	bit;
	static size_t	i;

	if (signal == SIGUSR1)
		ch = ch | (1 << bit);
	else if (signal == SIGUSR2)
		ch = ch | (0 << bit);
	bit++;
	if (bit == 8)
	{
		(*message)[i] = ch;
		i++;
		if (ch == '\0')
		{
			ft_printf("%s \n", *message);
			free(*message);
			*message = NULL;
			i = 0;
			*b = 0;
			*len = 0;
		}
		bit = 0;
		ch = 0;
	}
}

void	signal_handler(pid_t signal)
{
	static unsigned int	len;
	static size_t		bit;
	static char			*message;

	if (bit >= 32)
	{
		if (message == NULL)
		{
			message = malloc(sizeof(char) * (len + 1));
			if (message == NULL)
			{
				ft_printf("Memory allocation failed\n");
				exit(1);
			}
		}
		print_message(signal, &message, &bit, &len);
	}
	else if (bit < 32)
	{
		len = message_len(signal);
		bit++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("error in signal handler(SIGUSR1)");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("error in signal handler(SIGUSR2)");
		return (1);
	}
	while (1)
	{
		usleep(200);
	}
	return (0);
}
