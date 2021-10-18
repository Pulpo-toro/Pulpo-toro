#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	if (str1 < str)
	{
		while (len--)
		{
			str[len] = str1[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
