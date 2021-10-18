/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_another.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:26 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:27 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	close_mlx(t_mymlx **mymlx)
{
	if ((*mymlx)->img_p->img)
		mlx_destroy_image((*mymlx)->mlx, (*mymlx)->img_p->img);
	if ((*mymlx)->img_b->img)
		mlx_destroy_image((*mymlx)->mlx, (*mymlx)->img_b->img);
	if ((*mymlx)->img_cl->img)
		mlx_destroy_image((*mymlx)->mlx, (*mymlx)->img_cl->img);
	if ((*mymlx)->img_ex->img)
		mlx_destroy_image((*mymlx)->mlx, (*mymlx)->img_ex->img);
	if ((*mymlx)->img_wl->img)
		mlx_destroy_image((*mymlx)->mlx, (*mymlx)->img_wl->img);
	if ((*mymlx)->win)
		mlx_destroy_window((*mymlx)->mlx, (*mymlx)->win);
	if ((*mymlx)->mlx)
		mlx_destroy_display((*mymlx)->mlx);
	clean_data_0(mymlx);
	return (1);
}

int	hook_key(int keycode, t_mymlx **mymlx)
{
	if (keycode == ESC)
		close_mlx(mymlx);
	else if (keycode == W)
		(*mymlx)->permission = W;
	else if (keycode == S)
		(*mymlx)->permission = S;
	else if (keycode == A)
		(*mymlx)->permission = A;
	else if (keycode == D)
		(*mymlx)->permission = D;
	if (check_environment(mymlx) == -1)
		close_mlx(mymlx);
	return (keycode);
}

int	render_next_frame(t_mymlx **mymlx)
{
	write_image(*mymlx);
	player(mymlx);
	return (1);
}

int	hook(t_mymlx **mymlx)
{
	mlx_loop_hook((*mymlx)->mlx, render_next_frame, mymlx);
	mlx_hook((*mymlx)->win, 2, 1L << 0, hook_key, mymlx);
	mlx_hook((*mymlx)->win, 33, 1L << 5, close_mlx, mymlx);
	mlx_loop((*mymlx)->mlx);
	return (1);
}
