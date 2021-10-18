#include "ft_printf.h"

int	define_width_x(t_lists *structure, unsigned int p, int symbol)
{
	if (structure->width > 0 && p == 0 && structure->precision == 0)
		return (structure->width);
	else
		return (structure->width - symbol);
	return (1);
}

int	flag_three_adding(t_lists *structure, unsigned int p, int w)
{
	if (structure->precision == 0 && p == 0 && w > 0)
	{
		while (structure->precision == 0 && p == 0 && (w--) > 0)
			write (1, " ", 1);
		return (1);
	}
	return (1);
}
