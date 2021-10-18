#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	unsigned int	n;
	char			j;

	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		n = -i;
	}
	else
		n = i;
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	j = (n % 10) + '0';
	ft_putchar_fd(j, fd);
}
