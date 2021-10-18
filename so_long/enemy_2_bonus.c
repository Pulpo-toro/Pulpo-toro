/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:12 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:35:19 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_environment_en_1(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == W
		&& (*mymlx)->array[index - 1][index_1] == '1')
		(*mymlx)->permission_en = -W;
	else if ((*mymlx)->permission_en == S
		&& (*mymlx)->array[index + 1][index_1] == '1')
		(*mymlx)->permission_en = -S;
	else if ((*mymlx)->permission_en == A
		&& (*mymlx)->array[index][index_1 - 1] == '1')
		(*mymlx)->permission_en = -A;
	else if ((*mymlx)->permission_en == D
		&& (*mymlx)->array[index][index_1 + 1] == '1')
		(*mymlx)->permission_en = -D;
	check_environment_en_2(mymlx, index, index_1);
	return (1);
}

int	check_environment_en_2(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == W
		&& (*mymlx)->array[index - 1][index_1] == 'E')
		(*mymlx)->permission_en = -W;
	else if ((*mymlx)->permission == S
		&& (*mymlx)->array[index + 1][index_1] == 'E')
		(*mymlx)->permission_en = -S;
	else if ((*mymlx)->permission_en == A
		&& (*mymlx)->array[index][index_1 - 1] == 'E')
		(*mymlx)->permission_en = -A;
	else if ((*mymlx)->permission_en == D
		&& (*mymlx)->array[index][index_1 + 1] == 'E')
		(*mymlx)->permission_en = -D;
	check_environment_en_3(mymlx, index, index_1);
	return (1);
}

int	check_environment_en_3(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == W
		&& (*mymlx)->array[index - 1][index_1] == 'C')
		(*mymlx)->permission_en = -W;
	else if ((*mymlx)->permission_en == S
		&& (*mymlx)->array[index + 1][index_1] == 'C')
		(*mymlx)->permission_en = -S;
	else if ((*mymlx)->permission_en == A
		&& (*mymlx)->array[index][index_1 - 1] == 'C')
		(*mymlx)->permission_en = -A;
	else if ((*mymlx)->permission_en == D
		&& (*mymlx)->array[index][index_1 + 1] == 'C')
		(*mymlx)->permission_en = -D;
	check_environment_en_4(mymlx, index, index_1);
	return (1);
}

int	check_environment_en_4(t_mymlx **mymlx, int index, int index_1)
{
	if ((*mymlx)->permission_en == W
		&& (*mymlx)->array[index - 1][index_1] == 'P')
		close_mlx(mymlx);
	else if ((*mymlx)->permission_en == S
		&& (*mymlx)->array[index + 1][index_1] == 'P')
		close_mlx(mymlx);
	else if ((*mymlx)->permission_en == A
		&& (*mymlx)->array[index][index_1 - 1] == 'P')
		close_mlx(mymlx);
	else if ((*mymlx)->permission_en == D
		&& (*mymlx)->array[index][index_1 + 1] == 'P')
		close_mlx(mymlx);
	return (1);
}
