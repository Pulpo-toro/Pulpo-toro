#include "libft.h"

static size_t	ft_count_world(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] && s[i + 1] == c)
			|| (s[i] != c && !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_cl(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	char	**array;
	size_t	i;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_count_world(s, c) + 1));
	if (!array)
		return (NULL);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < ft_count_world(s, c))
	{
		array[i] = ft_substr(s, start, ft_len(&s[start], c));
		if (!array[i])
			return (ft_cl(array));
		start += ft_len(&s[start], c);
		while (s[start] == c)
			start++;
	}
	array[i] = (NULL);
	return (array);
}
