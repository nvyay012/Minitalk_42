/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:37 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 02:24:40 by hbarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	bits_handler(int signal)
{
	static char	c;
	static int	i;

	if (signal == SIGUSR1)
	{
		c = (c << 1) | 1;
		i++;
	}
	if (signal == SIGUSR2)
	{
		c = (c << 1);
		i++;
	}
	if (i == 8)
	{
		write (1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	signal (SIGUSR1, bits_handler);
	signal (SIGUSR2, bits_handler);
	write (1, "The server running. It's PID is: ", 33);
	ft_putnbr(pid);
	ft_putstr ("\n");
	while (1)
	{
	}
	return (0);
}
