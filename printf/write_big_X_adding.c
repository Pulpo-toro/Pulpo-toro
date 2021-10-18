#include "ft_printf.h"

int	get_number_base_16_big_X(unsigned long long p, int base)
{
	unsigned long long		toggle;
	int						remains;

	remains = 0;
	toggle = 0;
	if (p > toggle)
	{
		remains = (p % base);
		p /= base;
		toggle = p;
		if (p != 0)
		{
			get_number_base_16_big_X(p, base);
		}
		chek_remains_big_X(remains);
	}
	else
		chek_remains_big_X(remains);
	return (1);
}

int	chek_remains_big_X(int remains)
{
	char	elem;

	if (remains == 10)
		write (1, "A", 1);
	else if (remains ==11)
		write (1, "B", 1);
	else if (remains == 12)
		write (1, "C", 1);
	else if (remains == 13)
		write (1, "D", 1);
	else if (remains == 14)
		write (1, "E", 1);
	else if (remains == 15)
		write (1, "F", 1);
	else
	{
		elem = remains + '0';
		write (1, &elem, 1);
	}
	return (1);
}

int	count_symbol_big_X(unsigned long long p, int base, int symbol)
{
	unsigned long long		toggle;

	toggle = 0;
	if (p == 0)
	{
		symbol = 1;
		return (symbol);
	}
	while (p > toggle)
	{
		p /= base;
		symbol++;
	}
	return (symbol);
}
