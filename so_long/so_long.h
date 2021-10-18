/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:46:08 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 17:18:34 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define M 64
# define A 97
# define W 119
# define D 100
# define S 115
# define ESC 65307

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_solong
{
	int				size_width;
	int				size_height;
}					t_solong;

typedef struct s_list
{
	char			*line;
	int				count_elem;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	void			*img;
	int				width;
	int				height;
}				t_data;

typedef struct s_mymlx
{
	t_data			*img_wl;
	t_data			*img_b;
	t_data			*img_p;
	t_data			*img_cl;
	t_data			*img_ex;
	char			*path_wl;
	char			*path_b;
	char			*path_p;
	char			*path_cl;
	char			*path_ex;
	char			**array;
	void			*mlx;
	void			*win;
	int				permission;
	int				size;
	int				count;
}				t_mymlx;

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_list		*create_list(char *line, int index);
void		receiving_list(t_list **list, char *line, int count);
void		del_list(t_list **list);
char		**read_of_ber(int fd, int rd);
int			ft_lstsize(t_list *lst);
char		*ft_strdup(const char *s1);
char		**write_in_array(t_list *list);
void		ft_lstadd_back(t_list **lst, t_list *new_1);
t_list		*ft_lstlast(t_list *lst);
void		del_array(char **array);
int			verify_array(char **array);
int			verify_array_content(char **array);
int			verify_array_rectangular(char **array);
int			verify_array_closed(char **array);
int			verify_array_closed_topdown(char *under_array);
int			verify_array_content_exactly_e(char **array);
int			verify_array_content_exactly_c(char **array);
int			verify_array_content_exactly_p(char **array);
int			so_long(char **array);
int			initialization_data_1(t_mymlx **mymlx);
t_solong	initialization_data_2(t_mymlx **mymlx);
int			write_image(t_mymlx *mymlx);
int			hook(t_mymlx **mymlx);
int			close_mlx(t_mymlx **mymlx);
int			render_next_frame(t_mymlx **mymlx);
int			hook_key(int keycode, t_mymlx **mymlx);
int			change_coordinates_p(t_mymlx **mymlx);
int			change_coordinates(t_mymlx **mymlx, int index, int index_1);
int			player(t_mymlx **mymlx);
int			check_environment(t_mymlx **mymlx);
int			initialization_data_0(t_mymlx **mymlx);
int			check_environment_1(t_mymlx **mymlx, int index, int index_1);
int			check_environment_2(t_mymlx **mymlx, int index, int index_1);
int			initialization_data_0_1(t_mymlx **mymlx);
void		clean_data_0(t_mymlx **mymlx);
void		initialization_data(t_mymlx **mymlx);
void		write_image_1(t_mymlx *mymlx, int index, int index_1);
void		clean_data_1(t_mymlx **mymlx);
int			check_environment_0(t_mymlx *mymlx);
int			check_environment_3(t_mymlx **mymlx, int index, int index_1);
void		size_check(t_mymlx *mymlx);
void		change_coordinates_1(t_mymlx **mymlx, int index, int index_1);
int			initialization_data_0_2(t_mymlx **mymlx);
int			ft_fd(int fd);
char		**read_of_ber_1(t_list *list);

#endif
