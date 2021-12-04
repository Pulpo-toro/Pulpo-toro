/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:30:36 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:20:04 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil_bonus.h"

int	check(int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "Error: Little data\n", 20);
		return (-1);
	}
	if (argc > 6)
	{
		write(2, "Error: Lost of data\n", 21);
		return (-1);
	}
	if (check_argv(argv) == -1)
		return (-1);
	return (0);
}

int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "Error: Incorrect symbol\n", 24);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
