#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;
	void			*d;

	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = str1[i];
		if (str1[i] == (unsigned char )c)
		{
			i++;
			d = &dst;
			return ((void *)d);
		}
		i++;
	}
	return (NULL);
}
