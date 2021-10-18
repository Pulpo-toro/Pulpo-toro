/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:10 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:12 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line(char **line, char **buffer, t_list **list)
{
	int		length;
	int		i;
	int		j;
	char	*last_point;

	i = 0;
	j = ft_strlen(*line);
	length = length_line(line, buffer, list, -1);
	last_point = *line;
	(*line)[length] = '\0';
	length = length + 1;
	while ((*line)[length] != '\0' && length <= j)
	{
		(*buffer)[i] = (*line)[length];
		i++;
		length++;
	}
	(*buffer)[i] = '\0';
	*line = ft_strjoin(NULL, *line);
	if (*line == NULL)
		return (-1);
	free(last_point);
	return (0);
}

void	free_malloc(char **str)
{
	free(*str);
	*str = NULL;
}

t_list	*creatte_list(int fd, char **buffer)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
	{
		return (NULL);
	}
	list->fd = fd;
	list->buffer = (char *)malloc((1 + 1) * sizeof(char));
	list->next = NULL;
	if (!(list->buffer))
	{
		free(list);
		return (NULL);
	}
	(list->buffer)[0] = '\0';
	*buffer = list->buffer;
	return (list);
}

void	dell_list(int fd, t_list **list)
{
	t_list	*elem;
	t_list	*elem_for_del;

	elem = *list;
	if ((*list)->fd == fd)
	{
		(*list) = (*list)->next;
		free(elem->buffer);
		free(elem);
	}
	else
	{
		while (elem->next && elem->next->fd != fd)
			elem = elem->next;
		elem_for_del = elem->next;
		elem->next = elem->next->next;
		free(elem_for_del->buffer);
		free(elem_for_del);
	}
}
