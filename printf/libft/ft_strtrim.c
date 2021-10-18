#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1) - 1;
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(&s1[i], 0, len - i + 1));
}
