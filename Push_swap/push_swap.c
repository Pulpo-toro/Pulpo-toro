#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;

	i = 0;
	if (verify_data(argv) == -1)
		return (-1);
	a = malloc(sizeof(int) * argc);
	if (a == NULL)
		return (-1);
	b = malloc(sizeof(int) * argc);
	if (b == NULL)
		return (-1);
	b [argc - 1] = 0;
	while (argv[i + 1])
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a[i] = 0;
	i = change_1(&a, &b, argc);
	free (a);
	free (b);
	return (finish(i));
}

int	change_1(int **a, int **b, int argc)
{
	t_puap	*struc;

	struc = malloc(sizeof(t_puap));
	if (struc == NULL)
		return (-1);
	struc->number_a = argc - 1;
	struc->number_b = 0;
	if (verify_repeat(*a, struc->number_a, argc) == -1)
	{
		free (struc);
		return (-1);
	}
	struc->almost_order = 0;
	if (struc->number_a <= 4)
		change_only_a(a, struc);
	if (order_chaos(*a, struc) == -1)
		super_method(a, b, struc);
	free (struc);
	return (1);
}
