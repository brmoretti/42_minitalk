/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:56:44 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/21 10:02:20 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static volatile short int	g_green_flag = 0;

static void	args_check(int argc, char **argv)
{
	char	*pid;

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

static void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		g_green_flag = 1;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("\n\033[0;32m--- MESSAGE SENT ---\033[0;0m\n", 1);
		exit (EXIT_SUCCESS);
	}
}

static void	send_message(pid_t server_pid, const char *msg)
{
	unsigned char		c;
	short int			i;

	while (*msg)
	{
		c = (unsigned char)*msg;
		i = 8;
		while (i--)
		{
			g_green_flag = 0;
			if (c >> i & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			while (!g_green_flag)
				;
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	end;

	args_check(argc, argv);
	pid = (pid_t)ft_atoi(argv[1]);
	if ((signal(SIGUSR1, sig_handler) == SIG_ERR)
		|| (signal(SIGUSR2, sig_handler) == SIG_ERR))
		errors(fail_set_signal);
	send_message(pid, argv[2]);
	end = (char)4;
	send_message(pid, &end);
	return (0);
}
