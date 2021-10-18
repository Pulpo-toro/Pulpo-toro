/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:38 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:33:41 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_data_0(t_mymlx **mymlx)
{
	if ((*mymlx)->img_ex != NULL)
		free((*mymlx)->img_ex);
	if ((*mymlx)->img_cl != NULL)
		free((*mymlx)->img_cl);
	if ((*mymlx)->img_p != NULL)
		free((*mymlx)->img_p);
	if ((*mymlx)->img_b != NULL)
		free((*mymlx)->img_b);
	if ((*mymlx)->img_wl != NULL)
		free((*mymlx)->img_wl);
	if ((*mymlx)->img_black != NULL)
		free((*mymlx)->img_black);
	if ((*mymlx)->img_up != NULL)
		free((*mymlx)->img_up);
	if ((*mymlx)->img_down != NULL)
		free((*mymlx)->img_down);
	if ((*mymlx)->img_en != NULL)
		free((*mymlx)->img_en);
	clean_data_1(mymlx);
}

int	initialization_data_0_3(t_mymlx **mymlx)
{
	(*mymlx)->path_up = ft_strdup("./image/ring64up.xpm");
	if ((*mymlx)->path_up == NULL)
		return (-1);
	(*mymlx)->path_down = ft_strdup("./image/ring64down.xpm");
	if ((*mymlx)->path_down == NULL)
		return (-1);
	return (1);
}

void	clean_data_1(t_mymlx **mymlx)
{
	if ((*mymlx)->path_ex != NULL)
		free((*mymlx)->path_ex);
	if ((*mymlx)->path_cl != NULL)
		free((*mymlx)->path_cl);
	if ((*mymlx)->path_p != NULL)
		free((*mymlx)->path_p);
	if ((*mymlx)->path_b != NULL)
		free((*mymlx)->path_b);
	if ((*mymlx)->path_wl != NULL)
		free((*mymlx)->path_wl);
	if ((*mymlx)->path_black != NULL)
		free((*mymlx)->path_black);
	if ((*mymlx)->path_up != NULL)
		free((*mymlx)->path_up);
	if ((*mymlx)->path_down != NULL)
		free((*mymlx)->path_down);
	if ((*mymlx)->path_en != NULL)
		free((*mymlx)->path_en);
	if ((*mymlx)->mlx != NULL)
		free ((*mymlx)->mlx);
	del_array((*mymlx)->array);
	free(*mymlx);
	exit (EXIT_SUCCESS);
}
