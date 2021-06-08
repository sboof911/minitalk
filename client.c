/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:32:41 by amaach            #+#    #+#             */
/*   Updated: 2021/06/08 18:19:28 by amaach           ###   ########.fr       */
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


int		main(int argc, char **argv)
{
	char	**tab;
	int		compt;
	int		i;

	i = 0;
    if (argc != 2)
	{
		printf("nombre d argument incompatible");
		return (0);
	}
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
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}