#include "pipex.h"

int	pre_definition_path_cmd(t_pipe *struc, char **argv)
{
	if (struc->cmd1 == NULL)
	{
		struc->arr_2 = ft_split(argv[2], ' ');
		struc->cmd1 = pre_prepare_to_exec_1(struc->arr_2[0]);
	}
	if (struc->cmd2 == NULL)
	{	
		struc->arr_3 = ft_split(argv[3], ' ');
		struc->cmd2 = pre_prepare_to_exec_1(struc->arr_3[0]);
	}
	if (struc->cmd2 != NULL && struc->flag == -1)
		return (1);
	else if (struc->cmd1 == NULL || struc->cmd2 == NULL)
	{
		write(2, "Command not found\n", 18);
		free_end(struc);
		free (struc);
		return (-1);
	}
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
		return (NULL);
	}
	else
		return (str);
}

void	free_end(t_pipe *struc)
{
	int	i;

	i = 0;
	while ((struc)->arr_2[i])
		free((struc)->arr_2[i++]);
	free((struc)->arr_2);
	i = 0;
	while ((struc)->arr_3[i])
		free((struc)->arr_3[i++]);
	free((struc)->arr_3);
	if (struc->cmd1 != NULL)
		free(struc->cmd1);
	if (struc->cmd2 != NULL)
		free(struc->cmd2);
}

void	add(t_pipe *struc)
{
	struc->cmd1 = NULL;
	struc->cmd2 = NULL;
}
