#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_lists
{
	int								flag;
	int								width;
	int								precision;
	char							type_argument;
	int								count_symbol;
}					t_lists;

int		ft_printf (const char *description, ...);
int		read_description(const char *descs, va_list *ptr,
			t_lists *structre, int i);
int		find_flag(const char *description, t_lists *structure, int index);
int		find_width(const char *description, t_lists *structure, int index);
int		find_precision(const char *description, t_lists *structure, int index);
int		asterisk_control(t_lists *structure, va_list *ptr);
int		define_data_write(t_lists *structure, va_list *ptr);
int		write_i_d(t_lists *structure, va_list *ptr);
int		my_write (char *string);
int		flag_minus_one_i(t_lists *structure, char	*string, int i_d);
int		flag_one_i(t_lists *structure, char *string, int i_d);
int		flag_two_i(t_lists *structure, int i_d, char *string);
int		flag_three_i(t_lists *structure, char *string, int i_d);
int		flag_minus_one_i_help(int w, int p, char *string);
int		flag_one_i_help(int w, int p, char *string);
int		flag_two_i_help(t_lists *structure, char *string);
int		flag_three_i_help(int w, int p, char *string);
int		help_i_d(t_lists *structure, int i_d, char *string);
int		count_symbol_for_i(t_lists *structure, char *sting);
int		define_width_i(t_lists *structure, char *string);
void	flag_two_i_help_help(t_lists *structure, char *string, int p, int w);
int		write_p(t_lists *structure, va_list *ptr);
int		flag_minus_one_p(t_lists *structure, unsigned long long p);
int		get_number_base_16(unsigned long long p, int base);
int		chek_remains(int remains);
int		count_symbol(unsigned long long p, int base, int symbol);
int		flag_one_p(t_lists *structure, unsigned long long p);
int		write_c(t_lists *structure, va_list *ptr);
int		flag_minus_one_c(t_lists *structure, char c);
int		flag_one_c(t_lists *structure, char c);
int		write_u(t_lists *structure, va_list *ptr);
int		flag_minus_one_u(t_lists *structure, char	*string);
int		flag_one_u(t_lists *structure, char	*string);
int		flag_two_u(t_lists *structure, char	*string);
int		flag_three_u(t_lists *structure, char	*string);
int		write_x(t_lists *structure, va_list *ptr);
int		flag_minus_one_x(t_lists *structure, unsigned int p);
int		flag_one_x(t_lists *structure, unsigned int p);
int		flag_two_x(t_lists *structure, unsigned int p);
int		flag_three_x(t_lists *structure, unsigned int p);
int		flag_two_x_adding(t_lists *structure, int w, int precision);
int		count_symbol_for_x(t_lists *structure, int string, unsigned int p);
int		define_width_x(t_lists *structure, unsigned int p, int symbol);
int		flag_three_adding(t_lists *structure, unsigned int p, int w);
int		write_big_X(t_lists *structure, va_list *ptr);
int		flag_minus_one_big_X(t_lists *structure, unsigned int p);
int		flag_one_big_X(t_lists *structure, unsigned int p);
int		flag_two_big_X(t_lists *structure, unsigned int p);
int		flag_three_big_X(t_lists *structure, unsigned int p);
int		get_number_base_16_big_X(unsigned long long p, int base);
int		chek_remains_big_X(int remains);
int		count_symbol_big_X(unsigned long long p, int base, int symbol);
int		write_s(t_lists *structure, va_list *ptr);
int		flag_minus_one_s(t_lists *structure, char *string, int lenght);
int		flag_one_s(t_lists *structure, char *string, int lenght);
int		my_write_s (char *string, int p);
int		count_symbol_for_s(t_lists *structure, int lenght);
#endif
