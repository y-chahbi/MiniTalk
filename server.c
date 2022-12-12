/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:47:16 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/12 20:51:07 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extra/libft.h"

void	reset(int *i, char *c, int *pid, siginfo_t *info)
{
	*i = 0;
	*c = 0;
	*pid = info->si_pid;
	write(1, "\n", 1);
}

void	handler(int signal, siginfo_t *info, void *ptr)
{
	static int	i;
	static char	c;
	static int	pid;

	(void) ptr;
	if (pid != info->si_pid)
		reset(&i, &c, &pid, info);
	if (signal == SIGUSR1)
		c = c << 1;
	else if (signal == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	if (i++ == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}