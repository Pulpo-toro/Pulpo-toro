#include "push_swap.h"

int	verify_data(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '0' && argv[i][j + 1])
			return (error_messange());
		while (argv[i][j])
		{	
			if (argv[i][j] < '0' || argv[i][j++] > '9')
				return (error_messange());
		}
		if (j > 9 || (argv[i][0] == '-' && j > 10))
		{
			if (ft_atoi_add(argv[i]) == -1)
				return (error_messange());
		}
		j = 0;
		i++;
	}
	return (1);
}

int	verify_repeat(int *a, int number, int argc)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (argc < 2)
	{
		write (2, "Error: no data\n", 15);
		return (-1);
	}
	while (i < number)
	{
		while (j < number)
		{
			if (a[i] == a[j++])
				return (error_messange());
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	error_messange(void)
{
	write (2, "Error: incorrect data\n", 22);
	return (-1);
}

int	order_chaos(int *a, t_puap *struc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < struc->number_a)
	{
		if (a[j++] < a[i++])
		{
			return (-1);
		}
	}
	return (1);
}

int	almost_order_chaos(int *a, int i, int j, t_puap *struc)
{
	int	min;

	min = definition_min_a(a, struc);
	if (j == struc->number_a)
		j = 0;
	while (a[j] != min)
	{
		if (j == struc->number_a)
			j = 0;
		if (i == struc->number_a)
		{
			i = 0;
			j = 1;
		}
		if (a[j] == min)
			return (1);
		if (a[j] < a[i])
		{
			struc->almost_order = -1;
			return (-1);
		}
		j++;
		i++;
	}
	return (1);
}
