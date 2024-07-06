/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:09:56 by sasano            #+#    #+#             */
/*   Updated: 2024/07/06 16:30:29 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

static void	ft_reserve(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		printf("Success\n");
		exit(0);
	}
}

static void	send_null(pid_t pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error("Error: Invalid PID\n");
		usleep(100);
	}
}

static void	ft_client(pid_t pid, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 8;
		while (j-- > 0)
		{
			if (str[i] & (1 << j))
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Error: Invalid PID\n");
			}
			else if (kill(pid, SIGUSR1) == -1)
				error("Error: Invalid PID\n");
			usleep(100);
		}
	}
	send_null(pid);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
		error("Error: Invalid argument\n");
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		error("Error: Invalid PID\n");
	sa.sa_sigaction = ft_reserve;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1 || sigaction(SIGUSR1, &sa, NULL) == -1)
		error("Error: sigaction or sigemptyset\n");
	ft_client(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
