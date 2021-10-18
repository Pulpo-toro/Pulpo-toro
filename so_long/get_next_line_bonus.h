/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeata <lbeata@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:46:36 by lbeata            #+#    #+#             */
/*   Updated: 2021/10/13 15:46:37 by lbeata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buffer;
	int				fd;
	struct s_list	*next;
}					t_list;

int		get_next_line(int fd, char **line);
int		allocating_memory(char **line, t_list **list, char **buffer, int fd);
int		read_file(int fd, char **buffer, char **line, t_list **list);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		length_line(char **line, char **buffer, t_list **list, int fd);
int		get_line(char **line, char **buffer, t_list **list);
void	free_malloc(char **str);
t_list	*creatte_list(int fd, char **buffer);
void	dell_list(int fd, t_list **list);
void	read_file_help(char **line, char **buffer, int count_read);

#endif
