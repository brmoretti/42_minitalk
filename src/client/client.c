/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:10:39 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/07 21:07:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static short int	g_receiver = 0;

void	args_check(int argc)
{
	if (argc < 3)
		errors(insufficient_args);
	else if (argc > 3)
		errors(too_many_args);
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
	static unsigned int	i = 0;

	g_receiver = 1;
	if	(signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_putnbr_fd(i, 1);
}

void	send_char_to_pid(char c, pid_t pid)
{
	short int i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
}
void	config_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char** argv)
{
	pid_t	pid;


	args_check(argc);
	pid = (pid_t)ft_atoi(argv[1]);
	sigemptyset();
	while (1)
		pause();
	return (0);
}
