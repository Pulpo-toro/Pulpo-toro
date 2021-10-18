/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:49 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:51 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization_data(t_mymlx **mymlx)
{
	(*mymlx)->img_b = NULL;
	(*mymlx)->img_cl = NULL;
	(*mymlx)->img_ex = NULL;
	(*mymlx)->img_p = NULL;
	(*mymlx)->img_wl = NULL;
	(*mymlx)->path_b = NULL;
	(*mymlx)->path_cl = NULL;
	(*mymlx)->path_ex = NULL;
	(*mymlx)->path_p = NULL;
	(*mymlx)->path_wl = NULL;
	(*mymlx)->permission = 0;
	(*mymlx)->count = 0;
}

int	initialization_data_0(t_mymlx **mymlx)
{
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
	(*mymlx)->img_b->img = NULL;
	(*mymlx)->img_wl->img = NULL;
	(*mymlx)->img_p->img = NULL;
	(*mymlx)->img_cl->img = NULL;
	(*mymlx)->img_ex->img = NULL;
	if (initialization_data_0_1(mymlx) == -1)
		return (-1);
	return (1);
}

int	initialization_data_0_1(t_mymlx **mymlx)
{
	if ((*mymlx)->size == 64)
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
	}
	else
	{
		if (initialization_data_0_2(mymlx) == -1)
			return (-1);
	}
	return (1);
}

int	initialization_data_0_2(t_mymlx **mymlx)
{
	(*mymlx)->path_ex = ft_strdup("./image/portal32.xpm");
	if ((*mymlx)->path_ex == NULL)
		return (-1);
	(*mymlx)->path_cl = ft_strdup("./image/ring32.xpm");
	if ((*mymlx)->path_cl == NULL)
		return (-1);
	(*mymlx)->path_p = ft_strdup("./image/Zmei32.xpm");
	if ((*mymlx)->path_p == NULL)
		return (-1);
	(*mymlx)->path_b = ft_strdup("./image/back32.xpm");
	if ((*mymlx)->path_b == NULL)
		return (-1);
	(*mymlx)->path_wl = ft_strdup("./image/wall32.xpm");
	if ((*mymlx)->path_wl == NULL)
		return (-1);
	return (1);
}
