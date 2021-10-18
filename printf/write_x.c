#include "ft_printf.h"

int	write_x(t_lists *structure, va_list *ptr)
{
	unsigned int	p;

	p = (va_arg(*ptr, unsigned int));
	if (structure->flag == -1)
		flag_minus_one_x(structure, p);
	if (structure->flag == 1)
		flag_one_x(structure, p);
	if (structure->flag == 2)
		flag_two_x(structure, p);
	if (structure->flag == 3)
		flag_three_x(structure, p);
	return (1);
}

int	flag_minus_one_x(t_lists *structure, unsigned int p)
{
	int	symbol;
	int	w;
	int	precision;

	symbol = count_symbol(p, 16, 0);
	w = define_width_x(structure, p, symbol);
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	precision = structure->precision - symbol;
	if (precision < 0)
		precision = 0;
	while (((w--) - precision) > 0)
		write (1, " ", 1);
	while ((precision--) > 0)
		write (1, "0", 1);
	while (structure->precision == 0 && p == 0 && (w--) > 0)
	{
		write (1, " ", 1);
		return (1);
	}
	if (structure->precision == 0 && p == 0)
		return (1);
	get_number_base_16(p, 16);
	return (1);
}

int	flag_one_x(t_lists *structure, unsigned int p)
{
	int	symbol;
	int	w;
	int	precision;

	symbol = count_symbol(p, 16, 0);
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	w = define_width_x(structure, p, symbol);
	precision = structure->precision - symbol;
	while ((precision--) > 0)
		write (1, "0", 1);
	precision = structure->precision - symbol;
	if (precision < 0)
		precision = 0;
	if (structure->precision == 0 && p == 0)
	{
		while ((w--) > 0)
			write (1, " ", 1);
		return (1);
	}
	if (structure->precision == 0 && p == 0)
		return (1);
	get_number_base_16(p, 16);
	while (((w--) - precision) > 0)
		write (1, " ", 1);
	return (1);
}

int	flag_two_x(t_lists *structure, unsigned int p)
{
	int	symbol;
	int	w;
	int	precision;

	symbol = count_symbol(p, 16, 0);
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	w = define_width_x(structure, p, symbol);
	precision = structure->precision - symbol;
	if (precision < 0)
		precision = 0;
	flag_two_x_adding(structure, w, precision);
	while ((precision--) > 0)
		write (1, "0", 1);
	if (structure->precision == 0 && p == 0)
		return (1);
	get_number_base_16(p, 16);
	return (1);
}

int	flag_three_x(t_lists *structure, unsigned int p)
{
	int	symbol;
	int	w;
	int	precision;

	symbol = count_symbol(p, 16, 0);
	structure->count_symbol += count_symbol_for_x(structure, symbol, p);
	w = define_width_x(structure, p, symbol);
	precision = structure->precision - symbol;
	while ((precision--) > 0)
		write (1, "0", 1);
	flag_three_adding(structure, p, w);
	if (structure->precision == 0 && p == 0)
		return (1);
	get_number_base_16(p, 16);
	precision = structure->precision - symbol;
	if (precision < 0)
		precision = 0;
	flag_two_x_adding(structure, w, precision);
	return (1);
}
