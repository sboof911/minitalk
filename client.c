/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:32:41 by amaach            #+#    #+#             */
/*   Updated: 2021/06/10 15:31:28 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_binaire(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(9);
	if (!(str))
		return (NULL);
	while (i < 7)
		str[i++] = '0';
	str[i] = '\0';
	while (i >= 0)
	{
		str[i] = n % 2 + 48;
		n /= 2;
		i--;
	}
	return (str);
}

int	ft_strisdigit(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_help(int compt, char **argv, int pid, char **tab)
{
	int		j;
	int		i;

	i = 0;
	while (i < compt)
	{
		tab[i] = ft_binaire((int) argv[1][i]);
		i++;
	}
	tab[i] = 0;
	i = -1;
	while (++i < compt)
	{
		j = 0;
		while (j < 8)
		{
			if (tab[i][j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
	}
}

void	ft_error(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("nombre d argument incompatible\n", 1);
		exit(0);
	}
	if (ft_strisdigit(argv[2]) == 0)
	{
		ft_putstr_fd("PID is not a number\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		compt;
	int		i;
	int		pid;

	ft_error(argc, argv);
	pid = ft_atoi(argv[2]);
	compt = ft_strlen(argv[1]);
	tab = (char **)malloc(compt + 1);
	if (!(tab))
		return (-1);
	i = -1;
	while (++i < compt)
	{
		tab[i] = (char *)malloc(9);
		if (!(tab[i]))
			return (-1);
	}
	ft_help(compt, argv, pid, tab);
	return (0);
}
