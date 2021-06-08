/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <amaach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:01:33 by amaach            #+#    #+#             */
/*   Updated: 2021/06/08 18:43:03 by amaach           ###   ########.fr       */
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

int		main()
{
	printf("%d", ft_bitoasc("01101111"));
	pause();
}