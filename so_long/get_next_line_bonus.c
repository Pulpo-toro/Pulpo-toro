/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:42:52 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:43:00 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	length_line(char **line, char **buffer, t_list **list, int fd)
{
	int	index;

	if ((*line) == NULL)
	{
		*line = ft_strjoin(*line, *buffer);
		if (*line == NULL)
		{
			dell_list(fd, list);
			buffer = NULL;
			return (-1);
		}
	}
	index = 0;
	while ((*line)[index])
	{
		if ((*line)[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!array)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	return (array);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list;
	char			*buffer;
	int				status;

	if (fd < 0 || !line || (allocating_memory(line, &list, &buffer, fd) == -1))
		return (-1);
	if (length_line(line, &buffer, &list, fd) == -1)
		return (-1);
	status = read_file(fd, &buffer, line, &list);
	if (status == -1)
	{
		dell_list(fd, &list);
		return (-1);
	}
	if (get_line(line, &buffer, &list) == -1)
	{
		dell_list(fd, &list);
		return (-1);
	}
	if (status == 0)
	{
		dell_list(fd, &list);
		return (0);
	}
	return (1);
}

int	allocating_memory(char **line, t_list **list, char **buffer, int fd)
{
	t_list	*pointer;

	*line = NULL;
	pointer = NULL;
	if (*list == NULL)
		*list = creatte_list(fd, buffer);
	else
	{
		pointer = *list;
		while (pointer->next != NULL && pointer->fd != fd)
			pointer = pointer->next;
		if (pointer->next == NULL && pointer->fd != fd)
			pointer->next = creatte_list(fd, buffer);
		else
			*buffer = pointer->buffer;
	}
	if (!(*list) || (pointer && !(pointer->next) && pointer->fd != fd))
		return (-1);
	return (1);
}

int	read_file(int fd, char **buffer, char **line, t_list **list)
{
	int		count_read;
	char	*last_pointer;

	count_read = 1;
	while ((length_line(line, buffer, list, -1) == ft_strlen(*line)))
	{
		count_read = read(fd, *buffer, 1);
		if (count_read == -1)
		{
			if (count_read == -1)
				free_malloc(line);
			return (count_read);
		}
		last_pointer = *line;
		read_file_help(line, buffer, count_read);
		free(last_pointer);
		if (*line == NULL)
			return (-1);
		if (count_read == 0)
			return (count_read);
	}
	return (1);
}
