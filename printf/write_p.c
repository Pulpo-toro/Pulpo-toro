#include "ft_printf.h"

int	write_p(t_lists *structure, va_list *ptr)
{
	unsigned long long	p;

	p = (va_arg(*ptr, unsigned long long));
	if (structure->flag == -1)
		flag_minus_one_p(structure, p);
	if (structure->flag == 1)
		flag_one_p(structure, p);
	return (1);
}

int	flag_minus_one_p(t_lists *structure, unsigned long long p)
{
	int	symbol;
	int	w;

	w = structure->width;
	symbol = count_symbol(p, 16, 0) + 2;
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	while ((w - symbol) > 0)
	{
		write (1, " ", 1);
		w--;
	}
	write (1, "0x", 2);
	get_number_base_16(p, 16);
	return (1);
}

int	flag_one_p(t_lists *structure, unsigned long long p)
{
	int	symbol;
	int	w;

	w = structure->width;
	symbol = count_symbol(p, 16, 0) + 2;
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	write (1, "0x", 2);
	get_number_base_16(p, 16);
	while ((w - symbol) > 0)
	{
		write (1, " ", 1);
		w--;
	}
	return (1);
}
