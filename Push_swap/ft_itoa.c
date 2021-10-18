#include "bonus_push_swap.h"

static void	ft_putnbr(long int nb, char *array, long int j, long int i)
{
	if (nb < 0)
	{
		nb *= -1;
		array[i] = '-';
		i = i + 1;
	}
	if (nb >= 10)
	{
		j = j - 1;
		ft_putnbr(nb / 10, array, j, i);
	}
	else
		j = j - 1;
	array[j] = (nb % 10) + '0';
}

static long int	ft_size(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i = i + 2;
	return (i);
}

char	*ft_itoa(long int n)
{
	char			*array;
	long int		j;
	long int		i;

	j = ft_size(n) - 1;
	i = 0;
	if (n == -2147483648)
	{
		array = ft_strdup("-2147483648");
		return (array);
	}
	array = (char *)malloc(sizeof(char) * ft_size(n));
	if (!array)
		return (NULL);
	array[j] = '\0';
	ft_putnbr(n, array, j, i);
	return (array);
}
