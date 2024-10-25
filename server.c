/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:47:43 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 20:04:25 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handl(int signal, siginfo_t *info, void *ptr)
{
	static int	i;
	static char	c;

	(void) info;
	(void) ptr;
	if (signal == SIGUSR1)
	{
		c = c << 1;
	}
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
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handl;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	ft_putstr("The PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
