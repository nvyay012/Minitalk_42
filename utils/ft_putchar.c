/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:43 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 00:59:11 by hbarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_valid_pid(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ')
		++i;
	if (str[i] == '-' && str[i + 1] != '0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		++i;
	j = ft_strlen(str) - 1;
	while (j >= 0 && str[j] == ' ')
		--j;
	if (i > j)
		return (0);
	while (str && str[i] && i <= j)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}
