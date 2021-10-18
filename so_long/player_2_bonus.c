/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:44:45 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:44:48 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
