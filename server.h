/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:51:26 by mehkekli          #+#    #+#             */
/*   Updated: 2023/11/24 15:51:28 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "signal.h"
# include "stdlib.h"
# include "ft_printf/ft_printf.h"

# define ERR_KILL "kill error, signal cannot be sent"
# define ERR_TOO_MANY_ARG "too many arguments"
# define ERR_SIGACTION "sigaction error"

typedef struct s_state
{
	unsigned char	c;
	int				i;
	pid_t			pid;
}	t_state;

#endif