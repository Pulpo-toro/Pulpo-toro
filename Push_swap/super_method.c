#include "push_swap.h"

int	super_method(int **a, int **b, t_puap *struc)
{
	int	mid;
	int	i;

	i = 0;
	mid = definition_middle_a(*a, struc);
	while (i < struc->number_a)
	{
		if ((*a)[i] != definition_max_a(*a, struc)
			&& (*a)[i] != definition_min_a(*a, struc))
		{
			send_to_b_order(a, b, struc, mid);
			i = 0;
		}
		else if (((*a)[i] == definition_max_a(*a, struc)
			|| (*a)[i] == definition_min_a(*a, struc)) && struc->number_a != 2)
		{
			ra(a, struc);
			i = 0;
		}
		else
			i++;
	}
	super_method_1(a, b, struc);
	return (1);
}

int	super_method_1(int **a, int **b, t_puap *struc)
{
	while (struc->number_a != struc->number_a + struc->number_b)
		make_near_order_a(a, b, struc);
	put_in_order_a(a, struc);
	return (1);
}

int	make_near_order_a(int **a, int **b, t_puap *struc)
{
	int	i;
	int	search_i;
	int	maybe_count;
	int	maybe_count_1;

	i = 0;
	search_i = 0;
	maybe_count = 2 * (struc->number_a + struc->number_b);
	while (i < struc->number_b)
	{
		maybe_count_1 = count_do(*a, *b, struc, i);
		if (maybe_count > maybe_count_1)
		{
			maybe_count = maybe_count_1;
			search_i = i;
			struc->super_method = struc->super_method_index_a;
		}
		i++;
	}
	make_order_a(a, b, struc, search_i);
	return (1);
}

int	make_order_a(int **a, int **b, t_puap *struc, int search_i)
{
	int	help;

	help = (*b)[search_i];
	if ((search_i + 1) <= struc->number_b / 2 + 1)
	{	
		while ((*b)[0] != help)
			rb(b, struc);
	}
	else
	{
		while ((*b)[0] != help)
			rrb(b, struc);
	}
	make_order_a_1(a, struc);
	pa(a, b, struc);
	return (1);
}

int	make_order_a_1(int **a, t_puap *struc)
{
	int	index;
	int	index_down;

	index = struc->super_method;
	if (index + 1 < struc->number_b / 2 + 1 && index != -1)
	{	
		while ((index--) + 1 > 0)
			ra(a, struc);
	}
	else if (index != -1)
	{
		index_down = struc->number_a - index - 1;
		while (index_down-- > 0)
			rra(a, struc);
	}
	return (1);
}
