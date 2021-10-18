/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:37:28 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:37:33 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_file_help(char **line, char **buffer, int count_read)
{
	(*buffer)[count_read] = '\0';
	if (count_read == 0)
	{
		(*buffer)[0] = '\n';
		(*buffer)[1] = '\0';
	}
	(*line) = ft_strjoin(*line, *buffer);
}
