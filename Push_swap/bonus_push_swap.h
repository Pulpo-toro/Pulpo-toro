#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_puap
{
	int				number_a;
	int				number_b;
	int				in_min_a;
	int				in_min_b;
	int				in_max_a;
	int				in_max_b;
	int				count;
	int				*times_to_b;
	char			rd;
}					t_puap;

int		ft_atoi(const char *str);
int		ft_atoi_add(const char *str);
int		verify_data(char **argv);
int		error_messange(void);
void	sa(int *a, int num);
void	sb(int *b, int num);
void	ss(int *a, int *b, int num);
void	sa_sb(int *a, int man);
int		pa(int **a, int **b, t_puap *struc);
int		pa_help(int **b, t_puap *struc, int tip);
int		pb(int **a, int **b, t_puap *struc);
int		ra_rb(int **a, t_puap *struc, int tip);
int		ra(int **a, t_puap *struc);
int		rb(int **b, t_puap *struc);
int		rr(int **a, int **b, t_puap *struc);
int		rra_rrb(int **a_b, t_puap *struc, int tip);
int		rra(int **a, t_puap *struc);
int		rrb(int **b, t_puap *struc);
int		rrr(int **a, int **b, t_puap *struc);
int		verify_repeat(int *a, int number, int argc);
int		order_chaos(int *a, t_puap *struc);
int		change_1(int **a, int **b, int argc);
int		help_pre_job_a(int **a, int i, t_puap *struc);
int		read_input(int **a, int **b, t_puap *struc);
int		handel_1(int **a, int **b, t_puap *struc, char *str);
int		handel_2(int **a, int **b, t_puap *struc, char *str);
int		handel_3(int **a, int **b, t_puap *struc, char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	out_put(int **a, t_puap *struc);
char	*ft_itoa(long int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		help_read_input(char *str, t_puap *struc, int status);
int		finish_bonus(int i);

#endif
