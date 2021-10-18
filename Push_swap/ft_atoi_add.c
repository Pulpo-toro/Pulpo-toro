#include "push_swap.h"

static long int	sum(int i, const char *str)
{
	long int	num;
	long int	sum;

	sum = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = str[i] - '0';
			sum = sum * 10 + num;
			i++;
		}
		return (sum);
	}
	else
		return (0);
}

int	ft_atoi_add(const char *str)
{
	long int	i;
	int			k;

	k = 1;
	i = 0;
	if (str[i] == '-')
	{
		k = -k;
		i++;
	}
	else if (str[i] == '+')
		i++;
	i = sum(i, str) * k;
	if (i > 2147483647 || i < -2147483648)
		return (-1);
	return (1);
}
