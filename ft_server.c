/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:09:52 by sasano            #+#    #+#             */
/*   Updated: 2023/12/01 10:58:05 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

static int	check_utf8(char c)
{
	unsigned char	byte;

	byte = (unsigned char)c;
	if (byte == 0)
		return (0);
	else if ((byte & 0x80) == 0)
		return (1);
	else if ((byte & 0xE0) == 0xC0)
		return (2);
	else if ((byte & 0xF0) == 0xE0)
		return (3);
	else if ((byte & 0xF8) == 0xF0)
		return (4);
	return (-1);
}

static void	ft_put_utf8(char c, int length)
{
	static char	utf8[4];
	static int	i;
	static int	utf8_len;

	if (length != -1)
		utf8_len = length;
	utf8[i++] = c;
	utf8_len--;
	if (utf8_len == 0)
	{
		ft_putstr_fd(utf8, 1);
		ft_memset(utf8, 0, sizeof(utf8));
		i = 0;
		utf8_len = 0;
	}
}

static void	ft_server(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	length;
	static int	client_pid;

	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c = c | (1 << (7 - i));
	else if (sig == SIGUSR1)
		c = c & ~(1 << (7 - i));
	i++;
	if (i == 8)
	{
		length = check_utf8(c);
		if (length == 0)
		{
			ft_putchar_fd('\n', 1);
			if (client_pid > 0)
			{
				if (kill(client_pid, SIGUSR1) == -1)
					error("Error: Invalid PID\n");
				client_pid = 0;
			}
		}
		else if (length == 1)
			ft_putchar_fd(c, 1);
		else
			ft_put_utf8(c, length);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_server;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
