#include "bonus_push_swap.h"

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
	finish_bonus(i);
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
	if (read_input(a, b, struc) == -1)
	{
		free (struc);
		return (-1);
	}
	free (struc);
	return (1);
}

int	read_input(int **a, int **b, t_puap *struc)
{
	int		status;
	char	*str;

	struc->count = 0;
	status = 1;
	while (status != 0)
	{
		str = malloc(sizeof(char *) * 5);
		if (str == NULL)
			return (-1);
		status = help_read_input(str, struc, status);
		if (status == -1)
			return (-1);
		if (handel_1(a, b, struc, str) == -1)
			return (-1);
		free (str);
		if (status != 0)
			struc->count++;
	}
	out_put(a, struc);
	return (1);
}

int	help_read_input(char *str, t_puap *struc, int status)
{
	char	rd;
	int		i;

	i = 0;
	rd = '0';
	while (rd != '\n' && status != 0)
	{
		status = read(0, &rd, 1);
		if (status == -1)
			return (-1);
		if (rd == '\n')
			str[i] = '\0';
		else
			str[i] = rd;
		i ++;
		struc->rd = rd;
	}
	return (status);
}
