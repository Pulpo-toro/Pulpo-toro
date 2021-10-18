#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	runner;

	if (!str)
		return (0);
	runner = 0;
	while (str[runner] != '\0')
		runner++;
	return (runner);
}
