#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t detsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (i < detsize)
	{
		while (src[j] != '\0' && j < (detsize - i - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[j + i] = '\0';
		return (i + ft_strlen(src));
	}
	else
		return (detsize + ft_strlen(src));
}
