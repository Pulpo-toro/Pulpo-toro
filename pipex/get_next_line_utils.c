#include "get_next_line.h"

size_t	ft_strleng(const char *str)
{
	size_t	runner;

	runner = 0;
	if (!str)
		return (0);
	while (str[runner] != '\0')
		runner++;
	return (runner);
}

int	get_lineg(char **buffer, char **line)
{
	int		length;
	char	*last_pointer;

	last_pointer = *line;
	length = length_lineg(*buffer);
	if (length == -4)
		length = ft_strleng(*buffer);
	*line = ft_substrg(*buffer, 0, length);
	free(last_pointer);
	if (*line == NULL)
	{
		free(*buffer);
		return (-1);
	}
	return (1);
}

char	*ft_substrg(char const *s, unsigned int start, size_t len)
{
	char		*array;
	size_t		i;

	i = 0;
	if (len > ft_strleng(s) - start)
		len = ft_strleng(s) - start;
	array = (char *)malloc(len + 1);
	if (!array)
		return (NULL);
	while (s[0] && s[start] != '\0' && i < len)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

int	get_leftg(char **buffer)
{
	int		length;
	char	*last_pointer;

	last_pointer = *buffer;
	length = length_lineg(*buffer);
	if (length == -4)
		length = ft_strleng(*buffer) - 1;
	(*buffer) = ft_substrg(*buffer, (length + 1),
			(ft_strleng(*buffer) - length - 1));
	free(last_pointer);
	if ((*buffer) == NULL)
	{	
		return (-1);
	}
	return (0);
}

void	free_mallocg(char **str)
{
	free(*str);
	*str = NULL;
}
