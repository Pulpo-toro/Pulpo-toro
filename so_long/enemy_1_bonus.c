/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:03 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 17:15:00 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_coordinates_en_d(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == D)
	{
		(*mymlx)->array[index][index_1] = '0';
		(*mymlx)->array[index][index_1 + 1] = 'M';
		(*mymlx)->permission_en_past = 0;
		(*mymlx)->permission_en_past_1 = 0;
	}
}

int	check_environment_en(t_mymlx **mymlx)
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
				if ((*mymlx)->permission_en < 0)
					(*mymlx)->permission_en_past_1++;
				direction_en(*mymlx);
				check_environment_en_1(mymlx, index, index_1);
				check_direction_en(*mymlx);
				return (1);
			}
			index_1++;
		}
		index++;
	}
	return (1);
}

void	check_direction_en(t_mymlx *mymlx)
{
	if (mymlx->permission_en_past == 0)
	{
		if (mymlx->permission_en == -W)
			mymlx->permission_en_past = W;
		else if (mymlx->permission_en == -S)
			mymlx->permission_en_past = S;
		else if (mymlx->permission_en == -A)
			mymlx->permission_en_past = A;
		else if (mymlx->permission_en == -D)
			mymlx->permission_en_past = D;
	}
	if ((mymlx->permission_en != -mymlx->permission_en_past)
		&& mymlx->permission_en_past_1 > 0)
	{
		if (mymlx->permission_en == W && mymlx->permission_en_past == S)
			mymlx->permission_en = -W;
		else if (mymlx->permission_en == D && mymlx->permission_en_past == A)
			mymlx->permission_en = -D;
		else if (mymlx->permission_en == S && mymlx->permission_en_past == W)
			mymlx->permission_en = -S;
		else if (mymlx->permission_en == A && mymlx->permission_en_past == D)
			mymlx->permission_en = -A;
	}
	check_direction_en_1(mymlx);
}

void	check_direction_en_1(t_mymlx *mymlx)
{
	if ((mymlx->permission_en == -mymlx->permission_en_past)
		&& mymlx->permission_en_past_1 > 0)
	{
		if (mymlx->permission_en == -A)
			mymlx->permission_en = D;
		else if (mymlx->permission_en == -D)
			mymlx->permission_en = A;
		else if (mymlx->permission_en == -S)
			mymlx->permission_en = W;
		else if (mymlx->permission_en == -W)
			mymlx->permission_en = S;
		mymlx->permission_en_past_1 = 0;
	}
}

void	direction_en(t_mymlx *mymlx)
{
	if (mymlx->permission_en == -W)
		mymlx->permission_en = D;
	else if (mymlx->permission_en == -S)
		mymlx->permission_en = A;
	else if (mymlx->permission_en == -A)
		mymlx->permission_en = W;
	else if (mymlx->permission_en == -D)
		mymlx->permission_en = S;
}
