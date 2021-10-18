/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:34:42 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:34:45 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_solong	initialization_data_2(t_mymlx **mymlx)
{
	t_solong	size_window;
	int			index;

	(*mymlx)->mlx = NULL;
	(*mymlx)->win = NULL;
	index = 0;
	while ((*mymlx)->array[index])
		index++;
	size_window.size_height = index;
	size_window.size_width = ft_strlen((*mymlx)->array[0]);
	return (size_window);
}

void	display_moves_bonus(t_mymlx **mymlx)
{
	int		res_x;
	int		res_y;
	char	*it;

	it = ft_itoa((*mymlx)->count);
	mlx_get_screen_size((*mymlx)->mlx, &res_x, &res_y);
	mlx_string_put((*mymlx)->mlx, (*mymlx)->win, 20, 20, WIGHT, it);
	free(it);
}
