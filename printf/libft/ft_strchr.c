#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*h;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			h = &s[i];
			return ((char *)h);
		}
		i++;
	}
	if (c == 0)
	{
		h = &s[i];
		return ((char *)h);
	}
	else
		return (NULL);
}
