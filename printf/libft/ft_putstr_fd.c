#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !c)
		return ;
	while (c[i] != '\0')
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}
