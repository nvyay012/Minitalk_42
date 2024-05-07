/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:35 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 01:20:41 by hbarda           ###   ########.fr       */
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
	while (str[i])
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
	if (ac == 3)
	{
		if (!is_valid_pid(av[1]) || ft_atoi(av[1]) < 0 || ft_strlen(av[1]) > 11)
		{
			ft_putstr ("\nInvalid PID");
			return (1);
		}
		send_bits(ft_atoi(av[1]), av[2]);
	}
	else
		ft_putstr ("\nArgs error");
	return (0);
}
