# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:57:43 by ychahbi           #+#    #+#              #
#    Updated: 2022/12/18 15:04:49 by ychahbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAND_C = client
MAND_S = server
BONS_C = client_b
BONS_S = server_b
SRC  = extra/ft_atoi.c extra/ft_isdigit.c extra/ft_putchar.c extra/ft_putnbr.c extra/ft_putstr.c
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
OBJ_ALL = $(SRC:.c=.o)

all: $(MAND_C) $(MAND_S)

$(MAND_C): $(OBJ_ALL) client.o
	$(CC) $(CFLAGS) $^ -o $@

$(MAND_S): $(OBJ_ALL) server.o
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONS_C) $(BONS_S)

$(BONS_C): $(OBJ_ALL) client_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

$(BONS_S): $(OBJ_ALL) server_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h extra/libft.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ_ALL) client.o server.o server_bonus.o client_bonus.o

fclean: clean
	$(RM) $(BONS_C) $(BONS_S) $(MAND_C) $(MAND_S)

re: fclean all

.PHONY: clean fclean all re bonus
