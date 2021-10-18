#include "ft_printf.h"

int	write_i_d(t_lists *structure, va_list *ptr)
{
	char	*string;
	int		i_d;

	i_d = va_arg(*ptr, int);
	string = ft_itoa(i_d);
	if (structure->flag == -1)
		flag_minus_one_i(structure, string, i_d);
	if (structure->flag == 1)
		flag_one_i(structure, string, i_d);
	if (structure->flag == 2 && i_d >= 0)
		flag_two_i(structure, i_d, string);
	if (structure->flag == 2 && i_d < 0)
		flag_two_i_help(structure, string);
	if (structure->flag == 3)
		flag_three_i(structure, string, i_d);
	free(string);
	return (1);
}

int	flag_minus_one_i(t_lists *structure, char *string, int i_d)
{
	int		w;
	int		p;

	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (i_d < 0)
	{	
		flag_minus_one_i_help(w, p, string);
		return (1);
	}
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	while (p-- > 0)
		write(1, "0", 1);
	help_i_d(structure, i_d, string);
	return (1);
}

int	flag_one_i(t_lists *structure, char	*string, int i_d)
{
	int		w;
	int		p;

	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (i_d < 0)
	{	
		flag_one_i_help(w, p, string);
		return (1);
	}
	if (p < 0)
		p = 0;
	while (p-- > 0)
		write(1, "0", 1);
	help_i_d(structure, i_d, string);
	p = structure->precision - ft_strlen(string);
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	return (1);
}

int	flag_two_i(t_lists *structure, int i_d, char *string)
{
	int		w;

	w = structure->width - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (structure->precision == -1)
	{
		while ((w--) > 0)
			write(1, "0", 1);
	}
	else
		flag_two_i_help_help(structure, string, 0, w);
	help_i_d(structure, i_d, string);
	return (1);
}

int	flag_three_i(t_lists *structure, char *string, int i_d)
{
	int		w;
	int		p;

	w = structure->width - ft_strlen(string);
	p = structure->precision - ft_strlen(string);
	structure->count_symbol += count_symbol_for_i(structure, string);
	w = define_width_i(structure, string);
	if (i_d < 0)
	{	
		flag_three_i_help(w, p, string);
		return (1);
	}
	if (p < 0)
		p = 0;
	while (p-- > 0)
		write(1, "0", 1);
	help_i_d(structure, i_d, string);
	p = structure->precision - ft_strlen(string);
	if (p < 0)
		p = 0;
	while (((w--) - p) > 0)
		write(1, " ", 1);
	return (1);
}
