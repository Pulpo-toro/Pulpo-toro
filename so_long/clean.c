/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:34:10 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:34:28 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	clean_data_1(mymlx);
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
	if ((*mymlx)->mlx != NULL)
		free ((*mymlx)->mlx);
	del_array((*mymlx)->array);
	free(*mymlx);
	exit (EXIT_SUCCESS);
}
