/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:01:33 by amaach            #+#    #+#             */
/*   Updated: 2021/06/10 13:37:40 by amaach           ###   ########.fr       */
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
	if (str)
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
	static int	i = 0;
	static char tmp[8];
	
	if (SIGUSR1 == pid)
	{
		tmp[i] = '0';
		// ft_putchar_fd('0', 1);
		i++;
	}
	else if (SIGUSR2 == pid)
	{
		tmp[i] = '1';
		// ft_putchar_fd('1', 1);
		i++;
	}
	if (i == 8)
	{
		printf("\n%s", tmp);
		i = 0;
	}
}

int		main()
{
	signal(SIGUSR1, ft_print);
	signal(SIGUSR2, ft_print);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1);
}