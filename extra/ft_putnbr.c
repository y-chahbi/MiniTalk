/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:34:48 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/12 08:46:09 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	mv;
	unsigned int	tmp;

	if (n < 0)
	{
		mv = -n;
		write(1, "-", 1);
	}
	else
		mv = n;
	if (mv <= 9)
	{
		tmp = mv + 48;
		write(1, &tmp, 1);
	}
	else
	{
		ft_putnbr(mv / 10);
		ft_putnbr(mv % 10);
	}
}