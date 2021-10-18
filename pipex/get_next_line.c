#include "get_next_line.h"

int	length_lineg(char *buffer)
{
	int	index;

	index = 0;
	if (!buffer)
		return (-4);
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (-4);
}

char	*ft_strjoing(char const *s1, char const *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s2) && !(s1))
		return (NULL);
	array = malloc((ft_strleng(s1) + ft_strleng(s2) + 1));
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
	char			*buffer_read;
	static char		*buffer;
	int				status;

	if (fd < 0 || !line)
		return (-1);
	if (allocating_memoryg(line, &buffer, &buffer_read) == -1)
		return (-1);
	status = read_fileg(fd, &buffer, &buffer_read);
	if (status == -1)
	{
		free_mallocg(line);
		return (-1);
	}
	if (get_lineg(&buffer, line) == -1)
		return (-1);
	if (get_leftg(&buffer) == -1)
		return (-1);
	if (status == 0)
	{
		free_mallocg(&buffer);
		return (0);
	}
	return (1);
}

int	read_fileg(int fd, char **buffer, char **buffer_read)
{
	int		count_read;
	char	*last_pointer;

	count_read = 1;
	while ((length_lineg(*buffer) == -4))
	{
		count_read = read(fd, *buffer_read, 10);
		if (count_read == -1 || count_read == 0)
		{
			if (count_read == -1)
				free(*buffer);
			free(*buffer_read);
			return (count_read);
		}
		last_pointer = *buffer;
		(*buffer_read)[count_read] = '\0';
		(*buffer) = ft_strjoing(*buffer, *buffer_read);
		free(last_pointer);
		if (*buffer == NULL)
		{
			return (-1);
		}
	}
	free(*buffer_read);
	return (1);
}

int	allocating_memoryg(char **line, char **buffer, char **buffer_read)
{
	*line = (char *)malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	(*line)[0] = '\0';
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc(sizeof(char));
		if (*buffer == NULL)
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
		(*buffer)[0] = '\0';
	}
	*buffer_read = malloc(sizeof(char) * (10 + 1));
	if (*buffer_read == NULL)
	{
		free(*line);
		*line = NULL;
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	return (0);
}
