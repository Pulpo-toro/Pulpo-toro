/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:11:56 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/02 00:14:23 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	sum(int i, const char *str)
{
	int	num;
	int	sum;

	sum = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = str[i] - '0';
			sum = sum * 10 + num;
			i++;
		}
		return (sum);
	}
	else
		return (0);
}

static int	ft(const char *str)
{
	if (ft_strlen(str) > 10)
	{
		write(2, "Error: Incorrect data\n", 22);
		return (-1);
	}
	if (ft_strlen(str) == 10)
	{
		if (ft_strncmp("2147483647", str, 10) < 0)
		{
			write(2, "Error: Incorrect data\n", 22);
			return (-1);
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	k;

	if (ft(str) == -1)
		return (-1);
	k = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		k = -k;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (sum(i, str) * k);
}
