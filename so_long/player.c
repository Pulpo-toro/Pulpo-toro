/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:06 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:45:07 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player(t_mymlx **mymlx)
{
	if ((*mymlx)->permission == W)
		change_coordinates_p(mymlx);
	else if ((*mymlx)->permission == S)
		change_coordinates_p(mymlx);
	else if ((*mymlx)->permission == A)
		change_coordinates_p(mymlx);
	else if ((*mymlx)->permission == D)
		change_coordinates_p(mymlx);
	return (1);
}

int	change_coordinates(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission == W)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index - 1][index_1] = 'P';
		(*mymlx)->count++;
		printf("%i\n", (*mymlx)->count);
	}
	else if ((*mymlx)->permission == S)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index + 1][index_1] = 'P';
		(*mymlx)->count++;
		printf("%i\n", (*mymlx)->count);
	}
	change_coordinates_1(mymlx, index, index_1);
	return (1);
}

int	change_coordinates_p(t_mymlx **mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while ((*mymlx)->array[index])
	{
		index_1 = 0;
		while ((*mymlx)->array[index][index_1])
		{
			if ((*mymlx)->array[index][index_1] == 'P')
			{
				change_coordinates(mymlx, index, index_1);
				(*mymlx)->permission = 0;
				return (1);
			}
			index_1++;
		}
		index++;
	}
	return (1);
}

int	check_environment(t_mymlx **mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while ((*mymlx)->array[index])
	{
		index_1 = 0;
		while ((*mymlx)->array[index][index_1])
		{
			if ((*mymlx)->array[index][index_1] == 'P')
			{
				if (check_environment_0(*mymlx) == 1)
				{
					if (check_environment_2(mymlx, index, index_1) == -1)
						return (-1);
				}
				check_environment_1(mymlx, index, index_1);
				return (1);
			}
			index_1++;
		}
		index++;
	}
	return (1);
}

int	check_environment_1(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission == W
		&& (*mymlx)->array[index - 1][index_1] == '1')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == S
		&& (*mymlx)->array[index + 1][index_1] == '1')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == A
		&& (*mymlx)->array[index][index_1 - 1] == '1')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == D
		&& (*mymlx)->array[index][index_1 + 1] == '1')
		(*mymlx)->permission = 0;
	check_environment_3(mymlx, index, index_1);
	return (1);
}
