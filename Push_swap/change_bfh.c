#include "push_swap.h"

int	count_do(int *a, int *b, t_puap *struc, int i)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	if ((i + 1) <= struc->number_b / 2 + 1)
		count = i;
	else
		count = struc->number_b - i;
	while (index + 1 < struc->number_a)
	{
		if (a[index] < b[i] && a[index + 1] > b[i])
		{
			if (index + 1 < struc->number_b / 2 + 1)
				count += index + 1;
			else
				count += struc->number_a - index - 1;
			struc->super_method_index_a = index;
		}
		index++;
	}
	if (a[index] < b[i] && a[0] > b[i])
		struc->super_method_index_a = -1;
	return (count);
}

int	help_pre_job_a(int **a, int i, t_puap *struc)
{
	while (i < struc->in_min_a - 1)
	{
		if (ra(a, struc) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	send_to_b_order(int **a, int **b, t_puap *struc, int mid)
{
	pb(a, b, struc);
	if ((*b)[0] >= mid && struc->number_b > 1)
		rrb(b, struc);
	return (1);
}

int	finish(int i)
{
	if (i == -1)
		return (-1);
	return (1);
}
