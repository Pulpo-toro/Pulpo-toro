#include "pipex_bonus.h"

int	here_doc(t_pipe *struc, char *limiter)
{
	char	*line;

	struc->flag = 1;
	struc->fd_file[0] = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (struc->fd_file[0] == -1)
		return (-1);
	while (get_next_line(0, &line) > 0
		&& ft_strncmp(line, limiter, ft_strlen(limiter) + 1) != 0)
	{	
		write(struc->fd_file[0], line, ft_strlen(line));
		write(struc->fd_file[0], "\n", 1);
		free(line);
	}
	free (line);
	close(struc->fd_file[0]);
	struc->fd_file[0] = open("here_doc", O_RDONLY);
	struc->number_pipe--;
	return (1);
}

char	*pre_prepare_to_exec_1(char *argv)
{
	int		k;
	char	*str;

	k = 0;
	if (access(argv, 0) == 0)
	{
		str = ft_strjoin(argv, "");
		k = 1;
	}
	if (k == 0)
	{
		write(2, "Command not found\n", 18);
		return (NULL);
	}
	else
		return (str);
}

int	pre_prepare_to_exec(t_pipe *struc, char **argv, int i)
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
		struc->cmd[j] = pre_prepare_to_exec_1(struc->array[j][0]);
		if (struc->cmd[j] == NULL && j > 0)
			return (-1);
		j++;
	}
	return (1);
}

int	add_open(int i)
{
	if (i == -1)
	{
		write(2, "Can't open outfile\n", 19);
		return (-1);
	}
	return (1);
}
