#include "push_swap.h"

int	definition_middle_b(int *b, t_puap *struc, int times)
{
	int	i;
	int	j;
	int	middle;
	int	min;

	i = 0;
	j = 1;
	min = definition_min_b(b, struc, times);
	while (j < struc->number_b / 2)
	{
		middle = definition_max_b(b, struc);
		while (i < struc->number_b)
		{
			if (b[i] < middle && b[i] > min)
				middle = b[i];
			i++;
		}
		min = middle;
		i = 0;
		j++;
	}
	if (j == 1)
		middle = min;
	return (middle);
}

int	definition_middle_a(int *a, t_puap *struc)
{
	int	i;
	int	j;
	int	middle;
	int	min;

	i = 0;
	j = 1;
	min = definition_min_a(a, struc);
	while (j < struc->number_a / 2 + 1)
	{
		middle = definition_max_a(a, struc);
		while (i < struc->number_a)
		{
			if (a[i] < middle && a[i] > min)
				middle = a[i];
			i++;
		}
		min = middle;
		i = 0;
		j++;
	}
	if (j == 1)
		middle = min;
	return (middle);
}
