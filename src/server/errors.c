/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:43:37 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/11 12:44:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	errors(int error_code)
{
	if (error_code == fail_set_signal)
		ft_putstr_fd("Fail to set signals SIGUSR1 or SIGUSR2\n", 2);
	exit (EXIT_FAILURE);
}
