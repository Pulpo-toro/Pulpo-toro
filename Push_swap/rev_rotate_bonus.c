#include "bonus_push_swap.h"

int	rra(int **a, t_puap *struc)
{
	if (rra_rrb(a, struc, 0) == -1)
		return (-1);
	return (1);
}

int	rrb(int **b, t_puap *struc)
{
	if (rra_rrb(b, struc, 1) == -1)
		return (-1);
	return (1);
}

int	rrr(int **a, int **b, t_puap *struc)
{
	if (rra_rrb(a, struc, 0) == -1)
		return (-1);
	if (rra_rrb(b, struc, 1) == -1)
		return (-1);
	return (1);
}

int	rra_rrb(int **a_b, t_puap *struc, int tip)
{
	int	*new;
	int	aim;
	int	i;

	if (tip == 1)
		aim = struc->number_b;
	else
		aim = struc->number_a;
	new = malloc(sizeof(int) * (aim + 1));
	if (new == NULL)
		return (-1);
	i = 0;
	while (i < (aim - 1))
	{
		new[i + 1] = (*a_b)[i];
		i++;
	}
	new[0] = (*a_b)[i];
	new[aim] = 0;
	free(*a_b);
	*a_b = new;
	return (1);
}
