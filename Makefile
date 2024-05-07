# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 00:58:52 by hbarda            #+#    #+#              #
#    Updated: 2024/05/07 00:59:00 by hbarda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minitalk
CC= cc
CFLAGS= -Wall -Wextra -Werror
S_SRCS= srcs/server.c
C_SRCS= srcs/client.c
SBONUS_SRCS= bonus/server_bonus.c
CBONUS_SRCS= bonus/client_bonus.c
LIBFT_SRCS= utils/ft_atoi.c utils/ft_putchar.c utils/ft_putnbr.c utils/ft_putstr.c utils/ft_strlen.c
S_OBJS= $(S_SRCS:.c=.o)
C_OBJS= $(C_SRCS:.c=.o)
SBONUS_OBJS= $(SBONUS_SRCS:.c=.o)
CBONUS_OBJS= $(CBONUS_SRCS:.c=.o)
LIBFT_OBJS= $(LIBFT_SRCS:.c=.o)


all: $(NAME)

$(NAME): server client
bonus: server_bonus client_bonus

server : $(S_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(S_OBJS) -o server
client : $(C_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(C_OBJS) -o client

server_bonus : $(SBONUS_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(SBONUS_OBJS) -o server_bonus
client_bonus : $(CBONUS_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(CBONUS_OBJS) -o client_bonus

clean:
	rm -f $(C_OBJS) $(LIBFT_OBJS) $(S_OBJS) $(SBONUS_OBJS) $(CBONUS_OBJS)
fclean: clean
	rm -f server client server_bonus client_bonus
re: fclean all

.PHONY: all clean fclean re%
