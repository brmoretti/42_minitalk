/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:32:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/16 23:51:53 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler(int signum, siginfo_t *info, void* ucontent)
{
	static short int		i = 7;
	static unsigned char	c = 0;

	(void)ucontent;
	if (signum == SIGUSR1)
		c |= 1 << i;
	if (i-- == 0)
	{
		if (c == 4)
		{
			ft_putstr_fd("\n\033[0;32m--- END OF MESSAGE ---\033[0;0m\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		c = 0;
		i = 7;
		if (c == 4)
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

void	set_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		errors(fail_set_signal);
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putchar_fd('\n', 1);
	set_signals();
	while (1)
		sleep(42);
	return (0);
}
