#include "pipex.h"

int	ft_pipe(t_pipe *struc, char **envp)
{
	int	id1;
	int	id2;

	if (pipe(struc->fd_pipe) == -1)
		return (-1);
	if (struc->flag != -1)
	{
		id1 = fork();
		if (id1 < 0)
			return (-1);
		if (id1 == 0)
			child_process_first(struc, envp);
	}
	id2 = fork();
	if (id2 < 0)
		return (-1);
	if (id2 == 0)
		child_process_second(struc, envp);
	close(struc->fd_pipe[0]);
	close(struc->fd_pipe[1]);
	close(struc->fd_file[0]);
	close(struc->fd_file[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (1);
}

void	child_process_first(t_pipe *struc, char **envp)
{
	dup2(struc->fd_file[0], STDIN_FILENO);
	dup2(struc->fd_pipe[1], STDOUT_FILENO);
	close(struc->fd_file[0]);
	close(struc->fd_file[1]);
	close(struc->fd_pipe[0]);
	close(struc->fd_pipe[1]);
	if (execve(struc->cmd1, struc->arr_2, envp) == -1)
	{
		write (2, "Command execution error\n", 24);
	}
}

void	child_process_second(t_pipe *struc, char **envp)
{
	dup2(struc->fd_pipe[0], STDIN_FILENO);
	dup2(struc->fd_file[1], STDOUT_FILENO);
	close(struc->fd_file[0]);
	close(struc->fd_file[1]);
	close(struc->fd_pipe[0]);
	close(struc->fd_pipe[1]);
	if (execve(struc->cmd2, struc->arr_3, envp) == -1)
	{
		write (2, "Command execution error\n", 24);
	}
}

void	ft_free(t_pipe *struc)
{
	int	i;

	i = 0;
	if (struc->cmd1 == NULL)
	{
		while ((struc)->arr_2[i])
			free((struc)->arr_2[i++]);
		free((struc)->arr_2);
	}
	i = 0;
	if (struc->cmd2 == NULL)
	{
		while ((struc)->arr_3[i])
			free((struc)->arr_3[i++]);
		free((struc)->arr_3);
	}
}
