#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

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
	int				almost_order;
	int				super_method_index_a;
	int				super_method;
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
int		change_only_a(int **a, t_puap *struc);
int		change_between_full(int **a, int **b, t_puap *struc);
int		definition_middle_a(int *a, t_puap *struc);
int		definition_middle_b(int *b, t_puap *struc, int times);
int		definition_min_a(int *a, t_puap *struc);
int		definition_min_b(int *b, t_puap *struc, int times);
int		put_in_order_a(int **a, t_puap *struc);
int		definition_max_a(int *a, t_puap *struc);
int		definition_max_b(int *b, t_puap *struc);
int		pre_job_a(int **a, t_puap *struc);
int		permission_for_next(int *a, t_puap *struc);
int		definition_max_only_a(int *a, int start, int separator);
int		create_list_sent(int index, t_puap *struc);
int		help_way_tbf(int i, int **a, int variable, t_puap *struc);
int		help_change_only_a(int **a, int i, int j, t_puap *struc);
int		right_order_bf(int **a, t_puap *struc);
int		almost_order_chaos(int *a, int i, int j, t_puap *struc);
int		help_pre_job_a(int **a, int i, t_puap *struc);
int		super_method(int **a, int **b, t_puap *struc);
int		send_to_b_order(int **a, int **b, t_puap *struc, int mid);
int		count_do(int *a, int *b, t_puap *struc, int i);
int		make_order_a_1(int **a, t_puap *struc);
int		make_order_a(int **a, int **b, t_puap *struc, int search_i);
int		make_near_order_a(int **a, int **b, t_puap *struc);
int		super_method_1(int **a, int **b, t_puap *struc);
int		finish(int i);

#endif
