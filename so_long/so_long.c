/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:20 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:45:21 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char **array)
{
	t_mymlx	*mymlx;

	mymlx = malloc(sizeof(t_mymlx));
	if (mymlx == NULL)
		return (-1);
	mymlx->array = array;
	size_check(mymlx);
	initialization_data(&mymlx);
	if (initialization_data_0(&mymlx) == -1)
	{
		free(mymlx);
		exit (EXIT_FAILURE);
	}
	initialization_data_1(&mymlx);
	return (1);
}

int	initialization_data_1(t_mymlx **mymlx)
{
	t_solong	size_window;

	size_window = initialization_data_2(mymlx);
	(*mymlx)->mlx = mlx_init();
	(*mymlx)->win = mlx_new_window((*mymlx)->mlx,
			size_window.size_width * (*mymlx)->size,
			size_window.size_height * (*mymlx)->size, "So_long");
	(*mymlx)->img_wl->img = mlx_xpm_file_to_image((*mymlx)->mlx,
			(*mymlx)->path_wl, &((*mymlx)->img_wl->width),
			&((*mymlx)->img_wl->height));
	(*mymlx)->img_b->img = mlx_xpm_file_to_image((*mymlx)->mlx,
			(*mymlx)->path_b, &((*mymlx)->img_b->width),
			&((*mymlx)->img_b->height));
	(*mymlx)->img_p->img = mlx_xpm_file_to_image((*mymlx)->mlx,
			(*mymlx)->path_p, &((*mymlx)->img_p->width),
			&((*mymlx)->img_p->height));
	(*mymlx)->img_cl->img = mlx_xpm_file_to_image((*mymlx)->mlx,
			(*mymlx)->path_cl, &((*mymlx)->img_cl->width),
			&((*mymlx)->img_cl->height));
	(*mymlx)->img_ex->img = mlx_xpm_file_to_image((*mymlx)->mlx,
			(*mymlx)->path_ex, &((*mymlx)->img_ex->width),
			&((*mymlx)->img_ex->height));
	printf("%i\n", (*mymlx)->count);
	hook(mymlx);
	return (1);
}

int	write_image(t_mymlx *mymlx)
{
	int	index;
	int	index_1;

	index = 0;
	while (mymlx->array[index])
	{
		index_1 = 0;
		while (mymlx->array[index][index_1])
		{
			write_image_1(mymlx, index, index_1);
			index_1++;
		}
		index++;
	}
	return (1);
}

void	write_image_1(t_mymlx *mymlx, int index, int index_1)
{
	if (mymlx->array[index][index_1] == '1')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_wl->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == '0')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_b->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'P')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_p->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'C')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_cl->img, index_1 * mymlx->size, index * mymlx->size);
	if (mymlx->array[index][index_1] == 'E')
		mlx_put_image_to_window(mymlx->mlx, mymlx->win,
			mymlx->img_ex->img, index_1 * mymlx->size, index * mymlx->size);
}
