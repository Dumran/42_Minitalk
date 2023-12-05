/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:50:04 by mehkekli          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:06 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_state	g_state;

void	exit_err(int err_no, char *err)
{
	ft_printf("excited with (%d): %s\n", err_no, err);
	exit(err_no);
}

void	sigusr_cont_handler(int signum, siginfo_t *info, void *context)
{
	unsigned char	tmp;

	(void)signum;
	(void)info;
	(void)context;
	if (g_state.i >= 8)
	{
		g_state.i = 0;
		g_state.str++;
		if (*(g_state.str) == '\0')
			exit(0);
	}
	tmp = (*(g_state.str) & 1);
	*(g_state.str) >>= 1;
	g_state.i++;
	if (kill(g_state.pid, tmp + SIGUSR1) == -1)
		exit_err(5, ERR_KILL);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		exit_err(1, ERR_ARGUMENT);
	if (ac > 3)
		exit_err(2, ERR_TOO_MANY_ARG);
	g_state.pid = ft_atoi(av[1]);
	g_state.str = av[2];
	g_state.i = 0;
	g_state.sa.sa_flags = SA_SIGINFO;
	g_state.sa.sa_sigaction = sigusr_cont_handler;
	if (sigaction(SIGUSR1, &(g_state.sa), NULL) == -1)
		exit_err(4, ERR_SIGACTION);
	sigusr_cont_handler(0, NULL, NULL);
	while (1)
		pause();
	return (0);
}
