/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:49:57 by mehkekli          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:00 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "signal.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define ERR_KILL "kill error, signal cannot be sent"
# define ERR_TOO_MANY_ARG "too many arguments"
# define ERR_ARGUMENT "there have to be at least 2 arguments"
# define ERR_SIGACTION "sigaction error"
# define ERR_PID "pid is not valid"

typedef struct s_state
{
	struct sigaction	sa;
	pid_t				pid;
	char				*str;
	int					i;
}	t_state;

#endif