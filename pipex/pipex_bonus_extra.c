#include "pipex_bonus.h"

int	ft_pipe(t_pipe *struc, char **envp)
{
	int	id1;
	int	ind;

	ind = 0;
	id1 = 1;
	if (pipe(struc->fd_pipe_1) == -1)
		return (-1);
	if (pipe(struc->fd_pipe_2) == -1)
		return (-1);
	if (struc->flag == -1)
		ind++;
	while (ind < (struc->number_pipe))
	{
		ft_fork(struc, envp, ind, id1);
		ft_close(struc, ind);
		waitpid(id1, NULL, 0);
		ind++;
	}
	return (1);
}

int	child_process_first(t_pipe *struc, char **envp, int ind)
{
	if (ind == 0)
		dup2(struc->fd_file[0], STDIN_FILENO);
	else if (ind % 2 == 1)
		dup2(struc->fd_pipe_1[0], STDIN_FILENO);
	else if (ind % 2 == 0 && ind != 0)
		dup2(struc->fd_pipe_2[0], STDIN_FILENO);
	if (struc->number_pipe == ind + 1)
		dup2(struc->fd_file[1], STDOUT_FILENO);
	else if (ind % 2 == 1 && struc->number_pipe != 0)
		dup2(struc->fd_pipe_2[1], STDOUT_FILENO);
	else if (ind == 0 || ind % 2 == 0)
		dup2(struc->fd_pipe_1[1], STDOUT_FILENO);
	if (ind == 0)
		close(struc->fd_file[0]);
	close(struc->fd_file[1]);
	close(struc->fd_pipe_1[0]);
	close(struc->fd_pipe_1[1]);
	close(struc->fd_pipe_2[0]);
	close(struc->fd_pipe_2[1]);
	if (execve(struc->cmd[ind], struc->array[ind], envp) == -1)
	{
		write (2, "Command execution error\n", 24);
		return (-1);
	}
	return (1);
}

void	ft_free(t_pipe *struc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < struc->number_pipe)
	{
		while ((struc)->array[i][j])
			free((struc)->array[i][j++]);
		free((struc)->array[i++]);
		j = 0;
	}
	free((struc)->array);
	i = 0;
	if (struc->flag_path == 0)
	{
		while ((struc)->path[i])
			free((struc)->path[i++]);
		free((struc)->path);
	}
	i = 0;
	while (i < struc->number_pipe)
		free((struc)->cmd[i++]);
	free((struc)->cmd);
}

void	ft_close(t_pipe *struc, int ind)
{
	if (ind == 0)
	{
		close(struc->fd_pipe_1[1]);
		close(struc->fd_file[0]);
	}
	else if (ind % 2 == 1)
	{
		close(struc->fd_pipe_2[1]);
		close(struc->fd_pipe_1[0]);
		unlink ("here_doc");
	}
	else if (ind % 2 == 0 && ind != 0)
	{
		close(struc->fd_pipe_2[0]);
		close(struc->fd_pipe_1[1]);
	}
	else if (struc->number_pipe == ind + 1)
		close (struc->fd_file[1]);
}

int	ft_fork(t_pipe *struc, char **envp, int ind, int id1)
{
	if (ind % 2 == 0 && ind != 0)
	{
		if (pipe(struc->fd_pipe_1) == -1)
			return (-1);
	}
	if (ind % 2 == 1 && ind > 1)
	{
		if (pipe(struc->fd_pipe_2) == -1)
			return (-1);
	}
	id1 = fork();
	if (id1 < 0)
		return (-1);
	if (id1 == 0)
	{
		if (child_process_first(struc, envp, ind) == -1)
			return (-1);
	}
	return (1);
}
