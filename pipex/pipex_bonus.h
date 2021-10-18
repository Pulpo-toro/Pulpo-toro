#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H 

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	int				fd_pipe_1[2];
	int				fd_pipe_2[2];
	int				fd_file[2];
	int				number_pipe;
	int				flag;
	int				flag_path;
	char			**path;
	char			***array;
	char			**cmd;
}					t_pipe;

int		open_files(t_pipe *struc, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		definition_path_cmd(t_pipe *struc, char **argv, char **envp);
int		ft_pipe(t_pipe *struc, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp( const char *s1, const char *s2, size_t n);
int		prepare_to_exec(t_pipe *struc, char **argv, int i);
char	*prepare_to_exec_1(t_pipe *struc, char *argv);
int		child_process_first(t_pipe *struc, char **envp, int ind);
void	ft_free(t_pipe *struc);
void	ft_close(t_pipe *struc, int ind);
int		ft_fork(t_pipe *struc, char **envp, int ind, int id1);
int		get_next_line(int fd, char **line);
int		here_doc(t_pipe *struc, char *limiter);
char	*pre_prepare_to_exec_1(char *argv);
int		pre_prepare_to_exec(t_pipe *struc, char **argv, int i);
int		add_open(int i);

#endif
