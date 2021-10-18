#include "push_swap.h"

int	change_only_a(int **a, t_puap *struc)
{
	int			i;
	int			j;
	int			min;

	i = 0;
	min = pre_job_a(a, struc);
	j = struc->in_min_a;
	while (i < struc->number_a && almost_order_chaos(*a, j, j + 1, struc) != 1)
	{
		j = i + 1;
		if (j == struc->number_a)
			j = 0;
		if ((*a)[j] == min)
		{
			i++;
			j++;
			if (j == struc->number_a)
				j = 0;
			else if (i == struc->number_a)
				i = 0;
		}
		i = help_change_only_a(a, i, j, struc);
	}
	put_in_order_a(a, struc);
	return (1);
}

int	help_change_only_a(int **a, int i, int j, t_puap *struc)
{
	if (((*a)[i] > (*a)[j]) && i < struc->number_a)
	{
		if ((i + 1) > (struc->number_a / 2) && (struc->number_a > 3))
		{
			while ((struc->number_a - (i++)) > 0)
				rra(a, struc);
			i = -1;
		}
		else
		{
			while (i-- > 0)
				ra(a, struc);
		}
		sa(*a, struc->number_a);
	}
	return (i + 1);
}

int	put_in_order_a(int **a, t_puap *struc)
{
	int	min;

	min = definition_min_a(*a, struc);
	while ((*a)[0] != min)
	{
		if (struc->in_min_a + 1 > (struc->number_a / 2))
			rra(a, struc);
		else
			ra(a, struc);
	}
	return (1);
}

int	pre_job_a(int **a, t_puap *struc)
{
	int	i;
	int	min;

	i = 0;
	min = definition_min_a(*a, struc);
	if (permission_for_next(*a, struc) == -1)
		return (min);
	if ((*a)[0] != min)
	{
		if (struc->in_min_a != 1)
			i = help_pre_job_a(a, i, struc);
		sa(*a, struc->number_a);
		i = 0;
		while (i < struc->in_min_a - 1)
		{
			rra(a, struc);
			sa(*a, struc->number_a);
			i++;
		}
	}
	return (min);
}

int	permission_for_next(int *a, t_puap *struc)
{
	int	up_max;
	int	down_max;

	if (struc->in_min_a + 1 == struc->number_a)
		return (-1);
	up_max = definition_max_only_a(a, 0, struc->in_min_a + 1);
	down_max = definition_max_only_a(a, struc->in_min_a + 1, struc->number_a);
	if (up_max > down_max)
		return (-1);
	else
		return (1);
}
