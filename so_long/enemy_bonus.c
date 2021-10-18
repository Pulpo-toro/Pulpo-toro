/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:28 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 17:16:58 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy(t_mymlx **mymlx)
{
	check_environment_en(mymlx);
	change_coordinates_en(mymlx);
	while ((*mymlx)->permission_en < 0)
	{
		check_environment_en(mymlx);
		change_coordinates_en(mymlx);
	}
	return (1);
}

void	magic(t_mymlx **mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while ((*mymlx)->array[index])
	{
		index_1 = 0;
		while ((*mymlx)->array[index][index_1])
		{
			if ((*mymlx)->array[index][index_1] == 'M')
			{
				magic_1(mymlx, index, index_1);
				return ;
			}
			index_1++;
		}
		index++;
	}
}

void	magic_1(t_mymlx **mymlx, int x, int y)
{
	int	index;
	int	index_1;

	index = 0;
	while ((*mymlx)->array[index])
	{
		index_1 = 0;
		while ((*mymlx)->array[index][index_1])
		{
			if ((*mymlx)->array[index][index_1] == 'E')
			{
				(*mymlx)->array[index][index_1] = 'M';
				(*mymlx)->array[x][y] = 'E';
				(*mymlx)->coen = 0;
				return ;
			}
			index_1++;
		}
		index++;
	}
}

int	change_coordinates_en_1(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == W)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index - 1][index_1] = 'M';
		(*mymlx)->permission_en_past = 0;
		(*mymlx)->permission_en_past_1 = 0;
	}
	else if ((*mymlx)->permission_en == S)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index + 1][index_1] = 'M';
		(*mymlx)->permission_en_past = 0;
		(*mymlx)->permission_en_past_1 = 0;
	}
	else if ((*mymlx)->permission_en == A)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index][index_1 - 1] = 'M';
		(*mymlx)->permission_en_past = 0;
		(*mymlx)->permission_en_past_1 = 0;
	}
	change_coordinates_en_d(mymlx, index, index_1);
	return (1);
}

int	change_coordinates_en(t_mymlx **mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while ((*mymlx)->array[index])
	{
		index_1 = 0;
		while ((*mymlx)->array[index][index_1])
		{
			if ((*mymlx)->array[index][index_1] == 'M')
			{
				change_coordinates_en_1(mymlx, index, index_1);
				(*mymlx)->permission = 0;
				return (1);
			}
			index_1++;
		}
		index++;
	}
	return (1);
}
