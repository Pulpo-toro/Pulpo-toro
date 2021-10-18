#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*h;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[j + i] && (j + i) < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				h = &haystack[i];
				return ((char *)h);
			}
		}
		i++;
	}
	return (NULL);
}
