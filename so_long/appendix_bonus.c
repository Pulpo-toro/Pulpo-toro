/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:31:47 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:32:57 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_image_1(t_mymlx *mymlx, int index, int index_1)
{
	if (mymlx->array[index][index_1] == '1' && index == 0 && index_1 == 0)
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_black->img, index_1 * mymlx->size, index * mymlx->size);
	else if (mymlx->array[index][index_1] == '1')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_wl->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == '0')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_b->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'P')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_p->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'C' && mymlx->count_cl < 50)
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_cl->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'C' && mymlx->count_cl > 50)
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_down->img, index_1 * mymlx->size, index * mymlx->size);
	write_image_2(mymlx, index, index_1);
}

void	write_image_2(t_mymlx *mymlx, int index, int index_1)
{
	if (mymlx->array[index][index_1] == 'C' && mymlx->count_cl > 100)
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_up->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'E')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_ex->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'M')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_en->img, index_1 * mymlx->size, index * mymlx->size);
}
