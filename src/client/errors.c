/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:21:58 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/07 17:31:23 by bmoretti         ###   ########.fr       */
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
	exit (EXIT_FAILURE);
}
