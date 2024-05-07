/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:48 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 02:24:10 by hbarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putstr(char *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
	}
}

void	message_received(int sig)
{
	(void)sig;
	ft_putstr("Message has been sent successfully!!!");
}
