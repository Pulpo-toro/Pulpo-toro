#include "ft_printf.h"

int	flag_minus_one_i_help(int w, int p, char *string)
{
	p++;
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	write(1, "-", 1);
	while (((w--) - p) > 0)
		write(1, " ", 1);
	while (p-- > 0)
		write(1, "0", 1);
	my_write (&string[1]);
	return (1);
}

int	flag_one_i_help(int w, int p, char *string)
{
	int	save_p;

	p++;
	if (p < 0)
		p = 0;
	save_p = p;
	write(1, "-", 1);
	while (p-- > 0)
		write(1, "0", 1);
	my_write (&string[1]);
	while (((w--) - save_p) > 0)
		write(1, " ", 1);
	return (1);
}

int	flag_two_i_help(t_lists *structure, char *string)
{
	int		w;
	int		p;

	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string) + 1;
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (structure->precision < 0)
	{
		write(1, "-", 1);
		while ((w--) > 0)
			write(1, "0", 1);
	}
	else
		flag_two_i_help_help(structure, string, p, w);
	my_write (&string[1]);
	return (1);
}

int	flag_three_i_help(int w, int p, char *string)
{
	int	save_p;

	p++;
	if (p < 0)
		p = 0;
	save_p = p;
	write(1, "-", 1);
	while (p-- > 0)
		write(1, "0", 1);
	my_write (&string[1]);
	while (((w--) - save_p) > 0)
		write(1, " ", 1);
	return (1);
}

int	count_symbol_for_i(t_lists *structure, char *string)
{
	int	p;
	int	w;
	int	str;

	p = structure->precision;
	w = structure->width;
	str = ft_strlen(string);
	if (p == 0 && string[0] == '0' && w == 0)
		return (0);
	if (p >= structure->width && p >= str && string[0] == '-')
		return (structure->precision + 1);
	if (p >= structure->width && p >= str)
		return (structure->precision);
	if (w >= str)
		return (w);
	if (str >= w)
		return (str);
	return (1);
}
