/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:33:08 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 14:33:10 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**write_in_array(t_list *list)
{
	char	**array;
	int		index;
	int		index_1;

	index = 0;
	array = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[ft_lstsize(list)] = NULL;
	while (list)
	{
		array[index] = malloc((list->count_elem + 1) * sizeof(char));
		if (array[index] == NULL)
			return (NULL);
		array[index][list->count_elem] = '\0';
		index_1 = 0;
		while (list->line[index_1])
		{
			array[index][index_1] = list->line[index_1];
			index_1++;
		}
		index++;
		list = list->next;
	}
	return (array);
}

void	del_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

char	**read_of_ber(int fd, int rd)
{
	int		count;
	t_list	*list;
	char	*line;

	count = 0;
	list = NULL;
	while (rd >= 0)
	{
		rd = get_next_line(fd, &line);
		if (rd == -1)
			exit (-1);
		if (line[0] != '\0')
			receiving_list(&list, line, count++);
		if (line[0] == '\0')
			rd = -4;
		free (line);
	}
	if (list == NULL)
	{
		write (2, "Error\n", 7);
		exit (EXIT_FAILURE);
	}
	return (read_of_ber_1(list));
}

char	**read_of_ber_1(t_list *list)
{
	char	**array;

	array = write_in_array(list);
	del_list(&list);
	if (verify_array(array) == -1)
	{
		del_array(array);
		exit (EXIT_FAILURE);
	}
	return (array);
}
