/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_array_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:26 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 17:15:30 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	verify_array(char **array)
{
	if (verify_array_rectangular(array) == -1)
		return (-1);
	if (verify_array_content(array) == -1)
		return (-1);
	if (verify_array_closed(array) == -1)
		return (-1);
	return (1);
}

int	verify_array_closed(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		if (index == 0 || array[index + 1] == NULL)
		{
			if (verify_array_closed_topdown(array[index]) == -1)
				return (-1);
		}
		if (array[index][0] != '1'
		|| array[index][ft_strlen(array[index]) - 1] != '1')
		{
			write(2, "Error: Map isn't closed\n", 25);
			return (-1);
		}
		index++;
	}
	return (1);
}

int	verify_array_closed_topdown(char *under_array)
{
	int	index;

	index = 0;
	while (under_array[index])
	{
		if (under_array[index] != '1')
		{
			write(2, " Error: Map isn't closed\n", 26);
			return (-1);
		}
		index++;
	}
	return (1);
}

int	verify_array_rectangular(char **array)
{
	int	index;
	int	count_symbol;

	index = 0;
	count_symbol = ft_strlen(array[index]);
	while (array[index])
	{
		if (count_symbol != (int)ft_strlen(array[index]))
		{
			write(2, "Error: Map isn't rectangular\n", 30);
			return (-1);
		}
		index++;
	}
	return (1);
}

int	verify_array_content(char **array)
{
	int	index;
	int	index_1;

	index = 0;
	while (array[index])
	{
		index_1 = 0;
		while (array[index][index_1])
		{
			if (array[index][index_1] != '1' && array[index][index_1] != '0'
			&& array[index][index_1] != 'C' && array[index][index_1] != 'P'
			&& array[index][index_1] != 'E' && array[index][index_1] != 'M')
			{
				write(2, "Error: Incorrect map content\n", 30);
				return (-1);
			}
			index_1++;
		}
		index++;
	}
	if (verify_array_content_exactly_e(array) == -1)
		return (-1);
	return (1);
}
