/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:44:38 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:44:39 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_environment_2(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission == W
		&& (*mymlx)->array[index - 1][index_1] == 'E')
		return (-1);
	else if ((*mymlx)->permission == S
		&& (*mymlx)->array[index + 1][index_1] == 'E')
		return (-1);
	else if ((*mymlx)->permission == A
		&& (*mymlx)->array[index][index_1 - 1] == 'E')
		return (-1);
	else if ((*mymlx)->permission == D
		&& (*mymlx)->array[index][index_1 + 1] == 'E')
		return (-1);
	return (1);
}

int	check_environment_0(t_mymlx *mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while (mymlx->array[index])
	{
		index_1 = 0;
		while (mymlx->array[index][index_1])
		{
			if (mymlx->array[index][index_1] == 'C')
				return (-1);
			index_1++;
		}
		index++;
	}
	return (1);
}

int	check_environment_3(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission == W
		&& (*mymlx)->array[index - 1][index_1] == 'E')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == S
		&& (*mymlx)->array[index + 1][index_1] == 'E')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == A
		&& (*mymlx)->array[index][index_1 - 1] == 'E')
		(*mymlx)->permission = 0;
	else if ((*mymlx)->permission == D
		&& (*mymlx)->array[index][index_1 + 1] == 'E')
		(*mymlx)->permission = 0;
	return (1);
}

void	size_check(t_mymlx *mymlx)
{
	int	index;

	index = 0;
	while (mymlx->array[index])
		index++;
	if (index * 64 > 1000)
		mymlx->size = 32;
	else
		mymlx->size = 64;
	if (ft_strlen(mymlx->array[0]) * 64 > 1900)
		mymlx->size = 32;
	else
		mymlx->size = 64;
}

void	change_coordinates_1(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission == A)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index][index_1 - 1] = 'P';
		(*mymlx)->count++;
		printf("%i\n", (*mymlx)->count);
	}
	else if ((*mymlx)->permission == D)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index][index_1 + 1] = 'P';
		(*mymlx)->count++;
		printf("%i\n", (*mymlx)->count);
	}
}
