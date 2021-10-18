#include "bonus_push_swap.h"

void	out_put(int **a, t_puap *struc)
{
	if (order_chaos (*a, struc) == 1)
		write (1, "OK\n", 3);
	else
	{
		if (struc->rd != '\n')
			write (1, "\n", 1);
		write (1, "KO\n", 3);
	}
}

int	handel_1(int **a, int **b, t_puap *struc, char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		sa(*a, struc->number_a);
	else if (ft_strncmp(str, "sb", 3) == 0)
		sb(*b, struc->number_a);
	else if (ft_strncmp(str, "ss", 3) == 0)
		ss(*a, *b, struc->number_a);
	else if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (pa(a, b, struc) == -1)
			return (-1);
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (pb(a, b, struc) == -1)
			return (-1);
	}
	else if (handel_2(a, b, struc, str) == -1)
		return (-1);
	else if (handel_3(a, b, struc, str) == -1)
		return (-1);
	return (1);
}

int	handel_2(int **a, int **b, t_puap *struc, char *str)
{
	if (ft_strncmp(str, "ra", 3) == 0)
	{
		if (ra(a, struc) == -1)
			return (-1);
	}
	else if (ft_strncmp(str, "rb", 3) == 0)
	{
		if (rb(b, struc) == -1)
			return (-1);
	}
	else if (ft_strncmp(str, "rr", 3) == 0)
	{
		if (rr(a, b, struc) == -1)
			return (-1);
	}
	return (1);
}

int	handel_3(int **a, int **b, t_puap *struc, char *str)
{
	if (ft_strncmp(str, "rra", 4) == 0)
	{
		if (rra(a, struc) == -1)
			return (-1);
	}
	else if (ft_strncmp(str, "rrb", 4) == 0)
	{
		if (rrb(b, struc) == -1)
			return (-1);
	}
	else if (ft_strncmp(str, "rrr", 4) == 0)
	{
		if (rrr(a, b, struc) == -1)
			return (-1);
	}
	return (1);
}

int	finish_bonus(int i)
{
	if (i == -1)
		return (-1);
	return (1);
}
