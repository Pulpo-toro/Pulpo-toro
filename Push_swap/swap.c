#include "push_swap.h"

void	sa(int *a, int num)
{
	sa_sb(a, num);
	write(1, "sa\n", 3);
}

void	sb(int *b, int num)
{
	sa_sb(b, num);
	write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int num)
{
	sa_sb(a, num);
	sa_sb(b, num);
	write(1, "ss\n", 3);
}

void	sa_sb(int *a_b, int num)
{
	int	i;
	int	a1;

	i = 0;
	if (i < num)
	{
		a1 = a_b[i];
		a_b[i] = a_b[i + 1];
		a_b[i + 1] = a1;
	}
}
