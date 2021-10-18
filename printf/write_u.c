#include "ft_printf.h"

int	write_u(t_lists *structure, va_list *ptr)
{
	char			*string;
	unsigned int	u;

	u = va_arg(*ptr, unsigned int);
	string = ft_itoa(u);
	if (structure->flag == -1)
		flag_minus_one_u(structure, string);
	if (structure->flag == 1)
		flag_one_u(structure, string);
	if (structure->flag == 2)
		flag_two_u(structure, string);
	if (structure->flag == 3)
		flag_three_u(structure, string);
	free(string);
	return (1);
}

int	flag_minus_one_u(t_lists *structure, char	*string)
{
	int		w;
	int		p;
	int		i_d;

	i_d = 1;
	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	while (p-- > 0)
		write(1, "0", 1);
	if (string[0] == '0')
		i_d = 0;
	help_i_d(structure, i_d, string);
	return (1);
}

int	flag_one_u(t_lists *structure, char	*string)
{
	int		w;
	int		p;
	int		i_d;

	i_d = 1;
	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (p < 0)
		p = 0;
	while (p-- > 0)
		write(1, "0", 1);
	if (string[0] == '0')
		i_d = 0;
	help_i_d(structure, i_d, string);
	p = structure->precision - ft_strlen(string);
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	return (1);
}

int	flag_two_u(t_lists *structure, char	*string)
{
	int		w;
	int		i_d;

	i_d = 1;
	w = structure->width - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (structure->precision < 0)
	{
		while ((w--) > 0)
			write(1, "0", 1);
	}
	else
		flag_two_i_help_help(structure, string, 0, w);
	if (string[0] == '0')
		i_d = 0;
	help_i_d(structure, i_d, string);
	return (1);
}

int	flag_three_u(t_lists *structure, char	*string)
{
	int		w;
	int		p;
	int		i_d;

	i_d = 1;
	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (p < 0)
		p = 0;
	while (p-- > 0)
		write(1, "0", 1);
	if (string[0] == '0')
		i_d = 0;
	help_i_d(structure, i_d, string);
	p = structure->precision - ft_strlen(string);
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	return (1);
}
