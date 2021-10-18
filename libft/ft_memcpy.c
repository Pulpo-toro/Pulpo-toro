#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	i = 0;
	if (str == src)
		return (dst);
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dst);
}
