/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:15:19 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:05:33 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_each_eat;
	long long int	time_ms;
	long long int	time_ms_start;
	int				flag;
	int				status;
	int				take_of;
	long int		*array_int;
	pthread_t		*ar;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	to_write;
}					t_data;

typedef struct s_array_struc
{
	int				id;
	long int		time_point;
	long int		time_to_die;
	int				flag;
	int				number_eat;
	t_data			*data;
}					t_array_struc;

void			*routine(void *m);
int				ft_atoi(const char *str);
void			ft_time(t_data *data);
long long int	ft_time_1(t_array_struc *array_struc);
int				write_information_in_data(t_data *data, char **argv, int argc);
int				write_information_in_data_1(t_data *data, char **argv);
int				check_argv(char **argv);
int				check_argc(int argc);
int				check(int argc, char **argv);
int				go_to_thead_0(t_data *data);
int				go_to_thead(t_data *data, pthread_t *ar);
t_array_struc	**creat_array_struc(t_data *data);
void			time_del_start_redundancy(t_data *data);
void			time_del_finish_redundancy(t_data *data);
void			ft_usleep(int ms);
void			cast_printf(t_array_struc *array_struc, char *str, int index);
int				check_life(t_array_struc **ar_st);
size_t			ft_strlen(const char *str);
int				ft_strncmp( const char *s1, const char *s2, size_t n);
int				check_life_1(t_array_struc **ar_st, int number_philo, int j);
void			ft_free(t_data *data);
void			ft_free_ar_st(t_array_struc **ar_st);
int				free_ft(t_data *data);

#endif
