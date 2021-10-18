#include "bonus_push_swap.h"

void	sa(int *a, int num)
{
	sa_sb(a, num);
}

void	sb(int *b, int num)
{
	sa_sb(b, num);
}

void	ss(int *a, int *b, int num)
{
	sa_sb(a, num);
	sa_sb(b, num);
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
