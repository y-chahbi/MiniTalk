/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:49:24 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/12 20:51:00 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "extra/libft.h"

void	send(int pid, char c)
{
	int	i;

	// if (c < 0 || c > 127)
	// 	return ;
	i = 7;
	while (i >= 0)
	{
		kill(pid, (1 & (c >> i)) + SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (write(1, "Invalid Pid.\n", 14));
		while (av[2][i])
			send(pid, av[2][i++]);
		send(pid, av[2][i]);
		return (0);
	}
	write(1, "Invalid Args.\n", 15);
	return (1);
}