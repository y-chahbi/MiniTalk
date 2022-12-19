/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:49:24 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 20:02:43 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_is_get;

static void	the_messege(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (1 & (c >> i)) + SIGUSR1);
		i--;
		usleep(100);
	}
}

static void	is_it(int signal, siginfo_t *info, void *ptr)
{
	(void) ptr;
	(void) info;
	if (signal == SIGUSR1)
		g_is_get = 1;
}

static void	putmychars(char *s)
{
	ft_putstr("Sent : ");
	ft_putstr(s);
	ft_putchar('\n');
	ft_putstr("Is Recived : ");
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					the_pid;
	int					i;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &is_it;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	if (ac == 3)
	{
		the_pid = ft_atoi(av[1]);
		if (the_pid <= 0)
			return (write(1, "Error!\n", 7));
		while (av[2][i])
			the_messege(the_pid, av[2][i++]);
		the_messege(the_pid, av[2][i]);
		putmychars(av[2]);
		if (g_is_get == 1)
			ft_putstr("Yes");
		else
			ft_putstr("No");
		return (0);
	}
	write(1, "Error!\n", 7);
	return (1);
}
