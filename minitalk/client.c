/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:50:54 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/22 11:25:09 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_errors(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Enter PID then the message\n");
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("PID must be a Postive number\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	send_message(char ch, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (ch & (1 << bit))
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		bit++;
		usleep(200);
	}
}

void	send_message_len(size_t len, pid_t ser)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if (len & (1 << bit))
			kill(ser, SIGUSR1);
		else
			kill(ser, SIGUSR2);
		bit++;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	pid_t			server;
	char			*message;
	unsigned int	len;
	size_t			i;

	i = 0;
	if (check_errors(argc, argv))
		return (1);
	server = ft_atoi(argv[1]);
	message = argv[2];
	len = (unsigned int)ft_strlen(message);
	send_message_len(len, server);
	while (message[i] != '\0')
	{
		send_message(message[i], server);
		i++;
		if (message[i] == '\0')
			send_message('\0', server);
	}
	return (0);
}
