#include "push_swap.h"

int	ra(int **a, t_puap *struc)
{
	if (ra_rb(a, struc, 0) == -1)
		exit (-1);
	write (1, "ra\n", 3);
	return (1);
}

int	rb(int **b, t_puap *struc)
{
	if (ra_rb(b, struc, 1) == -1)
		exit (-1);
	write (1, "rb\n", 3);
	return (1);
}

int	rr(int **a, int **b, t_puap *struc)
{
	if (ra_rb(a, struc, 0) == -1)
		exit (-1);
	if (ra_rb(b, struc, 1) == -1)
		exit (-1);
	write (1, "rr\n", 3);
	return (1);
}

int	ra_rb(int **a_b, t_puap *struc, int tip)
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
		new[i] = (*a_b)[i + 1];
		i++;
	}
	new[i] = (*a_b)[0];
	new[aim] = 0;
	free(*a_b);
	*a_b = new;
	return (1);
}
