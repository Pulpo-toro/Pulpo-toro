#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	array = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!array)
		return (NULL);
	while (s1[i] != '\0')
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
