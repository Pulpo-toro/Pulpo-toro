/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_data_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:35 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:42 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialization_data(t_mymlx **mymlx)
{
	(*mymlx)->img_b = NULL;
	(*mymlx)->img_cl = NULL;
	(*mymlx)->img_ex = NULL;
	(*mymlx)->img_p = NULL;
	(*mymlx)->img_wl = NULL;
	(*mymlx)->img_ex = NULL;
	(*mymlx)->img_p = NULL;
	(*mymlx)->img_b = NULL;
	(*mymlx)->path_b = NULL;
	(*mymlx)->path_cl = NULL;
	(*mymlx)->path_ex = NULL;
	(*mymlx)->path_p = NULL;
	(*mymlx)->path_wl = NULL;
	(*mymlx)->path_en = NULL;
	(*mymlx)->permission = 0;
	(*mymlx)->count_en = 0;
	(*mymlx)->count_cl = 0;
	(*mymlx)->coen = 0;
	(*mymlx)->permission_en = A;
	(*mymlx)->permission_en_past = 0;
	(*mymlx)->permission_en_past_1 = 0;
	(*mymlx)->count = 0;
}

int	initialization_data_0(t_mymlx **mymlx)
{
	(*mymlx)->img_en = malloc(sizeof(t_data));
	if ((*mymlx)->img_en == NULL)
		return (-1);
	(*mymlx)->img_b = malloc(sizeof(t_data));
	if ((*mymlx)->img_b == NULL)
		return (-1);
	(*mymlx)->img_wl = malloc(sizeof(t_data));
	if ((*mymlx)->img_wl == NULL)
		return (-1);
	(*mymlx)->img_p = malloc(sizeof(t_data));
	if ((*mymlx)->img_p == NULL)
		return (-1);
	(*mymlx)->img_cl = malloc(sizeof(t_data));
	if ((*mymlx)->img_cl == NULL)
		return (-1);
	(*mymlx)->img_ex = malloc(sizeof(t_data));
	if ((*mymlx)->img_ex == NULL)
		return (-1);
	if (initialization_data_0_0(mymlx) == -1)
		return (-1);
	if (initialization_data_0_1(mymlx) == -1)
		return (-1);
	return (1);
}

int	initialization_data_0_0(t_mymlx **mymlx)
{
	(*mymlx)->img_black = malloc(sizeof(t_data));
	if ((*mymlx)->img_black == NULL)
		return (-1);
	(*mymlx)->img_up = malloc(sizeof(t_data));
	if ((*mymlx)->img_up == NULL)
		return (-1);
	(*mymlx)->img_down = malloc(sizeof(t_data));
	if ((*mymlx)->img_down == NULL)
		return (-1);
	(*mymlx)->img_down->img = NULL;
	(*mymlx)->img_b->img = NULL;
	(*mymlx)->img_wl->img = NULL;
	(*mymlx)->img_cl->img = NULL;
	(*mymlx)->img_p->img = NULL;
	(*mymlx)->img_black->img = NULL;
	(*mymlx)->img_up->img = NULL;
	(*mymlx)->img_ex->img = NULL;
	(*mymlx)->img_en->img = NULL;
	return (1);
}

int	initialization_data_0_1(t_mymlx **mymlx)
{
	if ((*mymlx)->size == 64)
	{
		if (initialization_data_0_2(mymlx) == -1)
			return (-1);
	}
	(*mymlx)->img_b->img = NULL;
	(*mymlx)->img_cl->img = NULL;
	(*mymlx)->img_ex->img = NULL;
	(*mymlx)->img_p->img = NULL;
	(*mymlx)->img_wl->img = NULL;
	(*mymlx)->img_en->img = NULL;
	(*mymlx)->img_black->img = NULL;
	(*mymlx)->img_up->img = NULL;
	(*mymlx)->img_down->img = NULL;
	return (1);
}

int	initialization_data_0_2(t_mymlx **mymlx)
{
	(*mymlx)->path_ex = ft_strdup("./image/portal64.xpm");
	if ((*mymlx)->path_ex == NULL)
		return (-1);
	(*mymlx)->path_cl = ft_strdup("./image/ring64.xpm");
	if ((*mymlx)->path_cl == NULL)
		return (-1);
	(*mymlx)->path_p = ft_strdup("./image/Zmei64.xpm");
	if ((*mymlx)->path_p == NULL)
		return (-1);
	(*mymlx)->path_b = ft_strdup("./image/back64.xpm");
	if ((*mymlx)->path_b == NULL)
		return (-1);
	(*mymlx)->path_wl = ft_strdup("./image/wall64.xpm");
	if ((*mymlx)->path_wl == NULL)
		return (-1);
	(*mymlx)->path_en = ft_strdup("./image/magneto64.xpm");
	if ((*mymlx)->path_en == NULL)
		return (-1);
	(*mymlx)->path_black = ft_strdup("./image/wall64black.xpm");
	if ((*mymlx)->path_en == NULL)
		return (-1);
	if (initialization_data_0_3(mymlx) == -1)
		return (-1);
	return (1);
}
