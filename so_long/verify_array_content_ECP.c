/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_array_content_ECP.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:45:40 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 17:18:10 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_array_content_exactly_e(char **array)
{
	int	index;
	int	index_1;

	index = 0;
	while (array[index])
	{
		index_1 = 0;
		while (array[index][index_1])
		{
			if (array[index][index_1] == 'E')
			{
				if (verify_array_content_exactly_c(array) == -1)
					return (-1);
				return (1);
			}
			index_1++;
		}
		index++;
	}
	write(2, "Error: There is no E in the map\n", 33);
	return (-1);
}

int	verify_array_content_exactly_c(char **array)
{
	int	index;
	int	index_1;

	index = 0;
	while (array[index])
	{
		index_1 = 0;
		while (array[index][index_1])
		{
			if (array[index][index_1] == 'C')
			{
				if (verify_array_content_exactly_p(array) == -1)
					return (-1);
				return (1);
			}
			index_1++;
		}
		index++;
	}
	write(2, "Error: There is no C in the map\n", 33);
	return (-1);
}

int	verify_array_content_exactly_p(char **array)
{
	int	index;
	int	index_1;
	int	count;

	index = 0;
	count = 0;
	while (array[index])
	{
		index_1 = 0;
		while (array[index][index_1])
		{
			if (array[index][index_1] == 'P')
				count++;
			index_1++;
		}
		index++;
	}
	if (count == 0)
		write(2, "Error: There is no P in the map\n", 33);
	else if (count > 1)
		write(2, "Error: Too much P in the map\n", 30);
	else
		return (1);
	return (-1);
}
