/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:57:03 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/11 16:05:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# ifndef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 700
# endif

# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include <sys/types.h>
# include <signal.h>
# include "libft.h"

enum	e_errors
{
	fail_set_signal
};

void	errors(int error_code);

#endif
