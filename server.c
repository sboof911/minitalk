/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:01:33 by amaach            #+#    #+#             */
/*   Updated: 2021/06/10 15:49:45 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int i)
{
	int		n;

	n = 1;
	while (i > 0)
	{
		n = n * 2;
		i--;
	}
	return (n);
}

int	ft_bitoasc(char *str)
{
	int		n;
	int		i;
	int		compt;

	i = 0;
	n = 0;
	compt = 7;
	while (i < 8)
	{
		if (str[i] == '1')
			n = n + ft_pow(compt);
		compt--;
		i++;
	}
	return (n);
}

void	ft_print(pid_t pid)
{
	static int	i = 0;
	static char	tmp[8];

	if (SIGUSR1 == pid)
	{
		tmp[i] = '0';
		i++;
	}
	else if (SIGUSR2 == pid)
	{
		tmp[i] = '1';
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd((char)ft_bitoasc(tmp), 1);
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, ft_print);
	signal(SIGUSR2, ft_print);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		(void)1;
}
