#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			j;
	const char	*h;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			h = &s[i];
			j ++;
		}
		i++;
	}
	if (c == 0)
	{
		h = &s[i];
		return ((char *)h);
	}
	if (j == 0)
		return (NULL);
	return ((char *)h);
}
