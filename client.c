/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:46:02 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/20 21:50:09 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	the_messege(int pid, char c)
{
	int	i;

	if (c < 0 || c > 127)
		return ;
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
	int					the_pid;
	int					i;

	i = 0;
	if (ac == 3)
	{
		the_pid = ft_atoi(av[1]);
		if (the_pid <= 0)
			return (write(1, "Error!\n", 7));
		while (av[2][i])
			the_messege(the_pid, av[2][i++]);
		the_messege(the_pid, av[2][i]);
		return (0);
	}
	write(1, "Error!\n", 7);
	return (1);
}
