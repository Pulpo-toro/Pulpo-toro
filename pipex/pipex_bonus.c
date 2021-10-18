#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*struc;

	if (argc < 5)
	{
		write(2, "Please, write 4 arguments!\n", 28);
		return (-1);
	}
	struc = malloc(sizeof(t_pipe));
	if (struc == NULL)
		return (-1);
	struc->flag = 0;
	if (open_files(struc, argv) == -1)
		exit (-1);
	if (definition_path_cmd(struc, argv, envp) == -1)
		exit (-1);
	if (ft_pipe(struc, envp) == -1)
		exit (-1);
	ft_free(struc);
	free(struc);
	return (1);
}

int	open_files(t_pipe *struc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	struc->number_pipe = i - 3;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1) == 0)
	{
		if (here_doc(struc, argv[2]) == -1)
			return (-1);
	}
	else
	{
		struc->fd_file[0] = open(argv[1], O_RDONLY);
		if (struc->fd_file[0] == -1)
		{
			struc->flag = -1;
			write(2, "Can't open infile\n", 19);
		}
	}
	struc->fd_file[1] = open(argv[i - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (add_open(struc->fd_file[1]));
}

int	definition_path_cmd(t_pipe *struc, char **argv, char **envp)
{
	int	i;

	i = 0;
	struc->flag_path = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A')
		{
			if (envp[i][2] == 'T' && envp[i][3] == 'H')
			{
				struc->path = ft_split(envp[i], ':');
				if (prepare_to_exec(struc, argv, 1) == -1)
					return (-1);
				return (1);
			}
		}
		i++;
	}
	struc->flag_path = -1;
	if (pre_prepare_to_exec(struc, argv, 1) == -1)
		return (-1);
	return (1);
}

int	prepare_to_exec(t_pipe *struc, char **argv, int i)
{
	int	j;

	j = 0;
	struc->array = (char ***)(malloc(sizeof(char **) * struc->number_pipe));
	if (struc->array == NULL)
		return (-1);
	struc->cmd = (char **)(malloc(sizeof(char *) * struc->number_pipe));
	if (struc->cmd == NULL)
		return (-1);
	if (struc->flag == 1)
		i = 2;
	while (argv[i++] && argv[i + 1])
	{
		struc->array[j] = ft_split(argv[i], ' ');
		struc->cmd[j] = prepare_to_exec_1(struc, struc->array[j][0]);
		if (struc->cmd[j] == NULL)
		{
			struc->cmd[j] = pre_prepare_to_exec_1(struc->array[j][0]);
			if (struc->cmd[j] == NULL)
				return (-1);
		}
		j++;
	}
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
