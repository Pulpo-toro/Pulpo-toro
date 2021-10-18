#include "push_swap.h"

static int	sum(int i, const char *str)
{
	int	num;
	int	sum;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	k;

	k = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		k = -k;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (sum(i, str) * k);
}
