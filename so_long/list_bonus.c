/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:56 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:56 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	receiving_list(t_list **list, char *line, int count)
{
	int	index;

	index = 0;
	if (count == 0)
		(*list) = create_list(line, index);
	else
		ft_lstadd_back(list, create_list(line, index));
}

t_list	*create_list(char *line, int index)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
	{
		exit (-1);
	}
	list->count_elem = ft_strlen(line);
	list->line = (char *)malloc((list->count_elem + 1) * sizeof(char));
	list->next = NULL;
	if (!(list->line))
	{
		free(list);
		exit (-1);
	}
	while (line[index])
	{
		list->line[index] = line[index];
		index++;
	}
	list->line[index] = '\0';
	return (list);
}

void	del_list(t_list **list)
{
	t_list	*elem;

	while (*list)
	{
		elem = *list;
		free(elem->line);
		*list = elem->next;
		free(elem);
	}
}
