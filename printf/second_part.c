#include "ft_printf.h"

int	asterisk_control(t_lists *structure, va_list *ptr)
{
	if (structure->width == -4)
	{
		structure->width = va_arg(*ptr, int);
		if (structure->width < 0)
		{
			if (structure->flag == 3)
				structure->flag = 3;
			else if (structure->flag == 2)
				structure->flag = 3;
			else
				structure->flag = 1;
			structure->width = -(structure->width);
		}
	}
	if (structure->precision == -4)
		structure->precision = va_arg(*ptr, int);
	return (1);
}

int	define_data_write(t_lists *structure, va_list *ptr)
{
	if (structure->type_argument == 'i' || structure->type_argument == 'd')
		write_i_d(structure, ptr);
	else if (structure->type_argument == 'p')
		write_p(structure, ptr);
	else if (structure->type_argument == 'c')
		write_c(structure, ptr);
	else if (structure->type_argument == 'u')
		write_u(structure, ptr);
	else if (structure->type_argument == 'x')
		write_x(structure, ptr);
	else if (structure->type_argument == 'X')
		write_big_X(structure, ptr);
	else if (structure->type_argument == 's')
		write_s(structure, ptr);
	else if (structure->type_argument == '%')
	{
		structure->count_symbol++;
		write(1, "%", 1);
	}
	return (1);
}

int	my_write(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (i);
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}
