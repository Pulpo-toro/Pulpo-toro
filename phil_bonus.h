/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:15:19 by lbeata            #+#    #+#             */
/*   Updated: 2021/12/04 18:31:20 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_BONUS_H
# define PHIL_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_data
{
	int				num_phi;
	long long int	time_to_die_cont;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_each_eat;
	long long int	time_ms;
	long long int	time_ms_start;
	int				flag;
	int				id;
	int				status;
	int				take_of;
	int				number_eat;
	long int		*array_int;
	int				*pid;
	sem_t			*forks;
	sem_t			*deth;
	sem_t			*meals;
}					t_data;

void			routine(t_data *data);
void			routine_1(t_data *data);
int				ft_atoi(const char *str);
void			ft_time(t_data *data);
long long int	ft_time_1(t_data *data);
int				write_information_in_data(t_data *data, char **argv, int argc);
int				write_information_in_data_1(t_data *data, char **argv);
int				check_argv(char **argv);
int				check_argc(int argc);
int				check(int argc, char **argv);
int				go_to_thead_0(t_data *data);
int				go_to_thead(t_data *data);
void			time_del_start_redundancy(t_data *data);
void			time_del_finish_redundancy(t_data *data);
void			ft_usleep(int ms);
void			cast_printf(t_data *data, char *str, int index);
void			*check_life(void *m);
size_t			ft_strlen(const char *str);
int				ft_strncmp( const char *s1, const char *s2, size_t n);
void			ft_free(t_data *data);
int				free_ft(t_data *data);

#endif
