#include "ft_printf.h"

int	write_s(t_lists *structure, va_list *ptr)
{
	char	*string;
	int		lenght;

	string = va_arg(*ptr, char *);
	if (string == NULL)
		lenght = 6;
	else
		lenght = ft_strlen(string);
	if (structure->flag == -1)
		flag_minus_one_s(structure, string, lenght);
	if (structure->flag == 1)
		flag_one_s(structure, string, lenght);
	return (1);
}

int	flag_minus_one_s(t_lists *structure, char *string, int lenght)
{
	int		w;
	int		p;

	structure->count_symbol += count_symbol_for_s(structure, lenght);
	p = structure->precision;
	if (p < 0)
		p = lenght;
	if (p >= lenght)
		w = structure->width - lenght;
	else
		w = structure->width - p;
	while ((w--) > 0)
		write(1, " ", 1);
	my_write_s (string, p);
	return (1);
}

int	flag_one_s(t_lists *structure, char	*string, int lenght)
{
	int		w;
	int		p;

	structure->count_symbol += count_symbol_for_s(structure, lenght);
	p = structure->precision;
	if (p < 0)
		p = lenght;
	if (p >= lenght)
		w = structure->width - lenght;
	else
		w = structure->width - p;
	my_write_s (string, p);
	while ((w--) > 0)
		write(1, " ", 1);
	return (1);
}

int	my_write_s(char *string, int p)
{
	int	i;

	i = 0;
	if (string == NULL)
	{
		if (i < p)
			write(1, "(", 1);
		if (++i < p)
			write(1, "n", 1);
		if (++i < p)
			write(1, "u", 1);
		if (++i < p)
			write(1, "l", 1);
		if (++i < p)
			write(1, "l", 1);
		if (++i < p)
			write(1, ")", 1);
	}
	else
	{
		while (string[i] && i < p)
			write(1, &string[i++], 1);
	}
	return (1);
}

int	count_symbol_for_s(t_lists *structure, int lenght)
{
	int	p;
	int	w;
	int	str;

	p = structure->precision;
	w = structure->width;
	str = lenght;
	if (p < 0)
		p = str;
	if (p >= w && p <= str)
		return (p);
	if (w >= str)
		return (w);
	if (p <= str && p <= w)
		return (w);
	if (str >= w)
		return (str);
	return (1);
}
