#ifndef PIPEX_H
# define PIPEX_H 

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipe
{
	int				fd_pipe[2];
	int				fd_file[2];
	char			**path;
	char			**arr_2;
	char			**arr_3;
	char			*cmd1;
	char			*cmd2;
	int				flag;
}					t_pipe;

int		open_files(t_pipe *struc, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		definition_path_cmd(t_pipe *struc, char **argv, char **envp);
int		ft_pipe(t_pipe *struc, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
int		prepare_to_exec(t_pipe *struc, char **argv);
char	*prepare_to_exec_1(t_pipe *struc, char *argv);
void	child_process_first(t_pipe *struc, char **envp);
void	child_process_second(t_pipe *struc, char **envp);
void	ft_free(t_pipe *struc);
void	free_end(t_pipe *struc);
void	add(t_pipe *struc);
char	*pre_prepare_to_exec_1(char *argv);
int		pre_definition_path_cmd(t_pipe *struc, char **argv);

#endif
