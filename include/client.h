/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:56:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/07 21:03:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# ifndef _XOPEN_SOURCE
#  define _XOPEN_SOURCE 700
# endif
# include "libft.h"
# include <sys/types.h>
# include <signal.h>

enum	e_errors
{
	insufficient_args,
	too_many_args
};

void	errors(int error_code);

#endif
