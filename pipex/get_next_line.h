#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		allocating_memoryg(char **line, char **buffer, char **buf);
int		read_fileg(int fd, char **buffer, char **buf);
size_t	ft_strleng(const char *str);
char	*ft_strjoing(char const *s1, char const *s2);
int		length_lineg(char *buf);
char	*ft_substrg(char const *s, unsigned int start, size_t len);
int		get_lineg(char **buffer, char **line);
int		get_leftg(char **buffer);
void	free_mallocg(char **str);

#endif
