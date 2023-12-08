/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:32:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/07 17:37:28 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
	while (1)
		sleep (1);
	return (0);
}
