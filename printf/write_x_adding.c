#include "ft_printf.h"

int	flag_two_x_adding(t_lists *structure, int w, int precision)
{
	while (((w--) - precision) > 0)
	{
		if (structure->precision == -1 && structure->flag != 3)
			write (1, "0", 1);
		else
			write (1, " ", 1);
	}
	return (1);
}

int	help_i_d(t_lists *structure, int i_d, char *string)
{
	if (structure->precision == 0 && i_d == 0)
		return (0);
	else
		my_write(string);
	return (1);
}

int	count_symbol_for_x(t_lists *structure, int string, unsigned int p)
{
	int	precision;
	int	w;

	precision = structure->precision;
	w = structure->width;
	if (precision == 0 && p == 0 && w == 0)
		return (0);
	if (precision >= w && precision >= string)
		return (precision);
	if (precision >= w && precision <= string)
		return (string);
	if (w >= string)
		return (w);
	if (string >= w)
		return (string);
	return (1);
}

int	define_width_i(t_lists *structure, char *string)
{
	
	if (structure->width > 0 && string[0] == '0' && structure->precision == 0)
		return (structure->width);
	else
		return (structure->width - ft_strlen(string));

}

void	flag_two_i_help_help(t_lists *structure, char *string, int p, int w)
{
	int	i;

	i = 0;
	if (p == 0)
		p = structure->precision - ft_strlen(string);
	while (structure->precision < 0 && (w--) > 0)
	{
		if (string[i++] == '-')
			write(1, "-", 1);
		write(1, "0", 1);
	}
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	if (string[i] == '-')
		write(1, "-", 1);
	while (p-- > 0)
		write(1, "0", 1);
}
