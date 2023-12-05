/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:50:33 by mehkekli          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:34 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	exit_err(int err_no, char *err)
{
	ft_printf("excited with (%d): %s\n", err_no, err);
	exit(err_no);
}

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static t_state	state;

	if (info->si_pid != 0)
		state.pid = info->si_pid;
	(void)context;
	if (signum == SIGUSR2)
		state.c |= 0b10000000;
	state.c >>= 1;
	state.i++;
	if (state.i > 6)
	{
		ft_printf("%c", state.c);
		state.i = 0;
		state.c = 0;
	}
	if (kill(state.pid, SIGUSR1) == -1)
		exit_err(5, ERR_KILL);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 1)
		exit_err(1, ERR_TOO_MANY_ARG);
	(void)av;
	ft_printf("pid: %d\n", getpid());
	sa.sa_sigaction = sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit_err(2, ERR_SIGACTION);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit_err(3, ERR_SIGACTION);
	while (1)
		pause();
}
