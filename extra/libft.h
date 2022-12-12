/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:26:08 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/12 08:53:48 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_isdigit(int c);

int		ft_atoi(const char *str);

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	ft_putnbr(int n);

#endif