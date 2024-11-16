/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:09:52 by sasano            #+#    #+#             */
/*   Updated: 2024/11/13 18:39:26 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

static void	send_signal(int client_pid, int num)
{
	if (num == 1 && kill(client_pid, SIGUSR1) == -1)
		error("Error: Invalid PID\n");
	else if (num == 2 && kill(client_pid, SIGUSR2) == -1)
		error("Error: Invalid PID\n");
}

static void	ft_server(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int	client_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c = c | (1 << (7 - i));
	else if (sig == SIGUSR1)
		c = c & ~(1 << (7 - i));
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		if (!c)
			send_signal(client_pid, 2);
		else
			send_signal(client_pid, 1);
		client_pid = 0;
		i = 0;
		c = 0;
	}
	else
		send_signal(client_pid, 1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	if (sigemptyset(&sa.sa_mask))
		error("Error: sigemptyset\n");
	sa.sa_sigaction = ft_server;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		error("Error: sigaction\n");
	while (1)
		pause();
	return (0);
}
