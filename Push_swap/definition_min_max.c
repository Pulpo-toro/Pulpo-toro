#include "push_swap.h"

int	definition_min_a(int *a, t_puap *struc)
{
	int	i;
	int	min;

	i = 0;
	min = a[i];
	struc->in_min_a = 0;
	while ((i + 1) < struc->number_a)
	{
		if (a[i + 1] < min)
		{
			min = a[i + 1];
			struc->in_min_a = i + 1;
		}
		i++;
	}
	return (min);
}

int	definition_max_a(int *a, t_puap *struc)
{
	int	i;
	int	max;

	i = 0;
	max = a[i];
	struc->in_max_a = 0;
	while ((i + 1) < struc->number_a)
	{
		if (a[i + 1] > max)
		{
			max = a[i + 1];
			struc->in_max_a = i + 1;
		}
		i++;
	}
	return (max);
}

int	definition_min_b(int *b, t_puap *struc, int times)
{
	int	i;
	int	min;

	i = 0;
	min = b[i];
	struc->in_min_b = 0;
	while ((i + 1) < struc->times_to_b[times - 1])
	{
		if (b[i + 1] < min)
		{
			min = b[i + 1];
			struc->in_min_b = i + 1;
		}
		i++;
	}
	return (min);
}

int	definition_max_b(int *b, t_puap *struc)
{
	int	i;
	int	max;

	i = 0;
	max = b[i];
	struc->in_max_b = 0;
	while ((i + 1) < struc->number_b)
	{
		if (b[i + 1] > max)
		{
			max = b[i + 1];
			struc->in_max_b = i + 1;
		}
		i++;
	}
	return (max);
}

int	definition_max_only_a(int *a, int start, int separator)
{
	int	max;

	max = a[start];
	while ((start + 1) < separator)
	{
		if (a[start + 1] > max)
		{
			max = a[start + 1];
		}
		start++;
	}
	return (max);
}
