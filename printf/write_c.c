#include "ft_printf.h"

int	write_c(t_lists *structure, va_list *ptr)
{
	char	c;

	c = va_arg(*ptr, unsigned int);
	if (structure->flag == -1)
		flag_minus_one_c(structure, c);
	if (structure->flag == 1)
		flag_one_c(structure, c);
	return (1);
}

int	flag_minus_one_c(t_lists *structure, char c)
{
	int	w;

	w = structure->width;
	structure->count_symbol += count_symbol_for_x(structure, 1, 1);
	while (((w--) - 1) > 0)
		write(1, " ", 1);
	write(1, &c, 1);
	return (1);
}

int	flag_one_c(t_lists *structure, char c)
{
	int	w;

	write(1, &c, 1);
	w = structure->width;
	structure->count_symbol += count_symbol_for_x(structure, 1, 1);
	while (((w--) - 1) > 0)
		write(1, " ", 1);
	return (1);
}
