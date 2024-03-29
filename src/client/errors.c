/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:21:58 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/11 10:25:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	errors(int error_code)
{
	if (error_code == insufficient_args)
		ft_putstr_fd("Missing args. Usage: "
			"./client <server_PID> <string_to_send>\n", 2);
	else if (error_code == too_many_args)
		ft_putstr_fd("Too many args. Usage: "
			"./client <server_PID> <string_to_send>\n", 2);
	else if (error_code == fail_set_signal)
		ft_putstr_fd("Fail to set signals SIGUSR1 or SIGUSR2\n", 2);
	else if (error_code == invalid_pid)
		ft_putstr_fd("Invalid PID\n", 2);
	else if (error_code == invalid_message)
		ft_putstr_fd("Invalid message\n", 2);
	exit (EXIT_FAILURE);
}
