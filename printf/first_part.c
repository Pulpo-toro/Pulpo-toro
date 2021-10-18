#include "ft_printf.h"

int	ft_printf(const char *description, ...)
{
	int		index;
	va_list	ptr;
	t_lists	*structure;

	structure = malloc(sizeof(t_lists));
	structure->count_symbol = 0;
	va_start(ptr, description);
	index = 0;
	while (description[index] != '\0')
	{
		index = read_description(description, &ptr, structure, index);
	}
	index = structure->count_symbol;
	free (structure);
	va_end(ptr);
	return (index);
}

int	read_description(const char *desc, va_list *ptr, t_lists *structure, int i)
{
	int			index;
	const char	*description;

	index = i;
	description = desc;
	while (description[index])
	{
		if (description[index] == '%')
		{
			index = find_flag(description, structure, index);
			index = find_width(description, structure, index);
			index = find_precision(description, structure, index);
			structure->type_argument = description[index];
			asterisk_control(structure, ptr);
			define_data_write(structure, ptr);
			return (index + 1);
		}
		else
		{
			write (1, &description[index], 1);
			structure->count_symbol ++;
		}
		index++;
	}
	return (index);
}

int	find_flag(const char *description, t_lists *structure, int index)
{
	index++;
	(structure)->flag = -1;
	while (description[index] == '0' || description[index] == '-')
	{
		if (description[index] == '0')
		{
			if ((structure)->flag == 1 || (structure)->flag == 3)
				(structure)->flag = 3;
			else
				(structure)->flag = 2;
		}
		if (description[index] == '-')
		{
			if ((structure)->flag == 2 || (structure)->flag == 3)
				(structure)->flag = 3;
			else
				(structure)->flag = 1;
		}
		index++;
	}
	return (index);
}

int	find_width(const char *description, t_lists *structure, int index)
{
	int	sum;

	sum = 0;
	if (description[index] == '*')
	{
		(structure)->width = -4;
		return (index + 1);
	}
	while (description[index] >= '0' && description[index] <='9')
	{
		sum = 10 * sum + (description[index] - '0');
		index++;
	}
	(structure)->width = sum;
	return (index);
}

int	find_precision(const char *description, t_lists *structure, int index)
{
	int	sum;

	sum = 0;
	if (description[index] == '.')
	{
		index++;
		if (description[index] == '*')
		{
			(structure)->precision = -4;
			return (index + 1);
		}
		while (description[index] >= '0' && description[index] <='9')
		{
			sum = 10 * sum + (description[index] - '0');
			index++;
		}
		(structure)->precision = sum;
		return (index);
	}
	(structure)->precision = -1;
	return (index);
}
