#include "bonus_push_swap.h"

int	pb(int **a, int **b, t_puap *struc)
{
	int	i;
	int	*b_new;

	if (a[0])
	{
		b_new = malloc(sizeof(int) * (struc->number_b + 2));
		if (b_new == NULL)
			return (-1);
		i = 0;
		while (i < struc->number_b)
		{
			b_new[i + 1] = (*b)[i];
			i++;
		}
		b_new[0] = (*a)[0];
		b_new[struc->number_b + 1] = 0;
		struc->number_b += 1;
		free(*b);
		*b = b_new;
		if (pa_help(a, struc, 1) == -1)
			return (-1);
	}
	return (1);
}

int	pa(int **a, int **b, t_puap *struc)
{
	int	i;
	int	*a_new;

	i = 0;
	if (struc->number_b != 0)
	{
		a_new = malloc(sizeof(int) * (struc->number_a + 2));
		if (a_new == NULL)
			return (-1);
		i = 0;
		while (i < struc->number_a)
		{
			a_new[i + 1] = (*a)[i];
			i++;
		}
		a_new[0] = (*b)[0];
		a_new[struc->number_a + 1] = 0;
		struc->number_a += 1;
		free(*a);
		*a = a_new;
		if (pa_help(b, struc, 0) == -1)
			return (-1);
	}
	return (1);
}

int	pa_help(int **second, t_puap *struc, int tip)
{
	int	aim;
	int	i;
	int	*new;

	if (tip == 1)
		aim = struc->number_a;
	else
		aim = struc->number_b;
	new = malloc(sizeof(int) * aim);
	if (new == NULL)
		return (-1);
	i = 0;
	while ((i + 1) < aim)
	{
		new[i] = (*second)[i + 1];
		i++;
	}
	new[i] = 0;
	if (tip == 1)
		struc->number_a -= 1;
	else
		struc->number_b -= 1;
	free(*second);
	*second = new;
	return (1);
}
