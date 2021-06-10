/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:01:33 by amaach            #+#    #+#             */
/*   Updated: 2021/06/10 12:30:47 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_pow(int i)
{
	int		n;

	n = 1;
	while (i > 0)
	{
		n  = n * 2;
		i--;
	}
	return (n);
}

char	*ft_strjoinc(char *str, char c)
{
	int		i;
	int		compt;
	char	*s1;
	
	i = 0;
	compt = ft_strlen(str);
	if (!(s1 = malloc(compt + 2)))
		return NULL;
	while (i < compt)
	{
		s1[i] = str[i];
		i++;
	}
	free(str);
	s1[i] = c;
	s1[i + 1] = '\0';
	return (s1);
}

int		ft_bitoasc(char *str)
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
	if (SIGUSR1 == pid)
		ft_putchar_fd('1', 1);
	else if (SIGUSR2 == pid)
		ft_putchar_fd('0', 1);
}

int		main()
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_print);
	signal(SIGUSR2, ft_print);
	while (1);
}