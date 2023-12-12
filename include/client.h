/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:56:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/11 14:34:41 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifndef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 700
# endif

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "libft.h"

enum	e_errors
{
	insufficient_args,
	too_many_args,
	fail_set_signal,
	invalid_pid,
	invalid_message
};

void	errors(int error_code);

#endif
