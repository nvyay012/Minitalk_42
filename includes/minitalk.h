/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarda <hbarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:58:32 by hbarda            #+#    #+#             */
/*   Updated: 2024/05/07 02:24:00 by hbarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <bits/sigaction.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		is_valid_pid(char *str);
void	message_received(int sig);

#endif
