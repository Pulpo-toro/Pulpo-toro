#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*array;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	array = (char *)malloc(len + 1);
	if (!array)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
