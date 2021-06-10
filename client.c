/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:32:41 by amaach            #+#    #+#             */
/*   Updated: 2021/06/10 13:06:51 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_binaire(int n)
{
	char	*str;
	int		i;
    
	i = 0;
	if(!(str = (char *)malloc(9)))
		return (NULL);
	while (i < 7)
		str[i++] = '0';
	str[i] = '\0';
	while (i >= 0)
	{
		str[i] = n % 2 +  48;
		n /= 2;
		i--;
	}
	return (str);
}

int		ft_strisdigit(char *str)
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

int		main(int argc, char **argv)
{
	char	**tab;
	int		compt;
	int		i;
	int		j;
	int		pid;

	i = 0;
    if (argc != 3)
	{
		printf("nombre d argument incompatible\n");
		return (0);
	}
	if (ft_strisdigit(argv[2]) == 0)
	{
		printf("PID not a number\n");
		return (0);
	}
	pid = ft_atoi(argv[2]);
	compt = ft_strlen(argv[1]);
	if (!(tab = (char **)malloc(compt + 1)))
		return (-1);
	while (i < compt)
	{
		if (!(tab[i] = (char *)malloc(9)))
			return (-1);
		i++;
	}
	i = 0;
	while (i < compt)
	{
		tab[i] = ft_binaire((int) argv[1][i]);
		i++;
	}
	tab[i] = 0;
	i = 0;
	while (i < compt)
	{
		j = 0;
		printf("%s\n", tab[i]);
		while (j < 8)
		{
			if (tab[i][j] ==  '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	return (0);
}