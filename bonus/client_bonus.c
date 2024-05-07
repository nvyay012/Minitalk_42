/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:27 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 02:23:41 by hbarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bits(int pid, char *str)
{
	int		error;
	int		shift;
	size_t	i;

	i = 0;
	error = 0;
	while (i <= ft_strlen(str))
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				error = kill (pid, SIGUSR1);
			else
				error = kill (pid, SIGUSR2);
			usleep(150);
			shift--;
		}
		if (error == -1)
		{
			ft_putstr ("\nInvalid PID");
			exit (1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	signal (SIGUSR2, message_received);
	if (ac == 3)
	{
		if (!is_valid_pid(av[1]) || ft_atoi(av[1]) < 0)
		{
			write(1, "pid is invalid", 15);
			exit(1);
		}
		send_bits(ft_atoi(av[1]), av[2]);
	}
	else
	{
		ft_putstr("Args error...!");
		return (1);
	}
	return (0);
}
