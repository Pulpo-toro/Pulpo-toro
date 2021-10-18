#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*struc;

	if (argc != 5)
	{
		write(2, "Please, write 4 arguments!\n", 28);
		return (-1);
	}
	struc = malloc(sizeof(t_pipe));
	struc->flag = 0;
	if (struc == NULL)
		return (-1);
	if (open_files(struc, argv) == -1)
		exit (-1);
	if (definition_path_cmd(struc, argv, envp) == -1)
	{
		if (pre_definition_path_cmd(struc, argv) == -1)
			exit (-1);
	}
	if (ft_pipe(struc, envp) == -1)
		exit (-1);
	free_end(struc);
	free(struc);
	return (1);
}

int	open_files(t_pipe *struc, char **argv)
{
	struc->fd_file[0] = open(argv[1], O_RDONLY);
	if (struc->fd_file[0] == -1)
	{
		struc->flag = -1;
		write(2, "Can't open infile\n", 19);
	}
	struc->fd_file[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (struc->fd_file[1] == -1)
	{
		write(2, "Can't open outfile\n", 19);
		return (-1);
	}
	return (1);
}

int	definition_path_cmd(t_pipe *struc, char **argv, char **envp)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A')
		{
			if (envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				struc->path = ft_split(envp[i], ':');
				if (prepare_to_exec(struc, argv) == -1)
					return (-1);
				k++;
			}
		}
		i++;
	}
	if (k == 0)
	{
		add(struc);
		return (-1);
	}
	return (1);
}

int	prepare_to_exec(t_pipe *struc, char **argv)
{
	int	i;

	i = 0;
	struc->arr_2 = ft_split(argv[2], ' ');
	struc->arr_3 = ft_split(argv[3], ' ');
	struc->cmd1 = prepare_to_exec_1(struc, struc->arr_2[0]);
	struc->cmd2 = prepare_to_exec_1(struc, struc->arr_3[0]);
	while ((struc)->path[i])
	{
		free((struc)->path[i++]);
	}
	free((struc)->path);
	ft_free(struc);
	if (struc->cmd1 == NULL || struc->cmd2 == NULL)
		return (-1);
	return (1);
}

char	*prepare_to_exec_1(t_pipe *struc, char *argv)
{
	char	*str;
	char	*str1;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (struc->path[i] && k != 1)
	{
		str1 = ft_strjoin(struc->path[i], "/");
		str = ft_strjoin(str1, argv);
		free (str1);
		if (access(str, 0) == 0)
			k = 1;
		else
			free (str);
		i++;
	}
	if (k == 0)
	{
		return (NULL);
	}
	else
		return (str);
}
