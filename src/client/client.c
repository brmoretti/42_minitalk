/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:10:39 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/16 19:19:15 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static short int	green_flag = 0;

void	args_check(int argc, char **argv)
{
	char*	pid;

	if (argc < 3)
		errors(insufficient_args);
	else if (argc > 3)
		errors(too_many_args);
	pid = argv[1];
	while (*pid)
		if (!ft_isdigit(*(pid++)))
			errors(invalid_pid);
	if (*argv[2] == 0)
		errors(invalid_message);
}

void sig_handler(int signum)
{
	if (signum == SIGUSR1)
		green_flag = 1;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("\n\033[0;32m--- MESSAGE SENT ---\033[0;0m\n", 1);
		exit (EXIT_SUCCESS);
	}
}

void	send_message(pid_t server_pid, const char* msg)
{
	unsigned char		c;
	short int			i;

	while (*msg)
	{
		c = (unsigned char)*msg;
		i = 8;
		while (i--)
		{
			green_flag = 0;
			if (c >> i & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (!green_flag)
				;
		}
		msg++;
	}
}

void	set_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		errors(fail_set_signal);
}

int	main(int argc, char** argv)
{
	pid_t	pid;
	char	end;

	args_check(argc, argv);
	pid = (pid_t)ft_atoi(argv[1]);
	set_signals();
	send_message(pid, argv[2]);
	end = (char)4;
	send_message(pid, &end);
	return (0);
}
