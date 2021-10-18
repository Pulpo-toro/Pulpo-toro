#include "ft_printf.h"

int	get_number_base_16(unsigned long long p, int base)
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
			get_number_base_16(p, base);
		}
		chek_remains(remains);
	}
	else
		chek_remains(remains);
	return (1);
}

int	chek_remains(int remains)
{
	char	elem;

	if (remains == 10)
		write (1, "a", 1);
	else if (remains ==11)
		write (1, "b", 1);
	else if (remains == 12)
		write (1, "c", 1);
	else if (remains == 13)
		write (1, "d", 1);
	else if (remains == 14)
		write (1, "e", 1);
	else if (remains == 15)
		write (1, "f", 1);
	else
	{
		elem = remains + '0';
		write (1, &elem, 1);
	}
	return (1);
}

int	count_symbol(unsigned long long p, int base, int symbol)
{
	unsigned long long	toggle;

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
