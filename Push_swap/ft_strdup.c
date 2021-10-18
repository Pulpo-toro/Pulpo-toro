#include "bonus_push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*array;
	size_t	j;
	size_t	i;

	i = 0;
	j = ft_strlen(s1);
	array = (char *)malloc((j + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (i <= j)
	{
		array[i] = s1[i];
		i++;
	}
	return (array);
}
