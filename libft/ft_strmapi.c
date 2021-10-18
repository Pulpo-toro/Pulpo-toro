#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	array = ft_strdup(s);
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = (f)(i, array[i]);
		i++;
	}
	return (array);
}
