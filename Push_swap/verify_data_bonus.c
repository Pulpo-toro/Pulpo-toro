#include "bonus_push_swap.h"

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
		write (2, "Error\n", 6);
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
	write (2, "Error\n", 6);
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
