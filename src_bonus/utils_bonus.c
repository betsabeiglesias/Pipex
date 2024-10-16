/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:14 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 12:50:35 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_notused(t_pipex *pipex)
{
	int	j;

	j = 0;
	while (j < pipex->nb_cmd - 1)
	{
		if (j != pipex->idx_process)
			close(pipex->pipe[j][1]);
		if (j != pipex->idx_process - 1)
			close(pipex->pipe[j][0]);
		j++;
	}
}

void	check_params(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	if (argc < 5)
		error_exit("Incorrect arguments\n");
	if ((ft_strncmp(argv[1], "here_doc", 8) == 0))
	{
		i = -1;
		while (++i < argc - 1)
		{
			if (ft_strlen(argv[i]) == 0)
				error_exit("Incorrect arguments\n");
		}
		pipex->here_doc = 1;
	}
	else
	{
		i = -1;
		while (++i < argc - 1)
		{
			if (ft_strlen(argv[i]) == 0)
				error_exit("Incorrect arguments\n");
		}
		pipex->here_doc = 0;
	}
}

char	*find_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char	*get_command(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	error_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit (EXIT_FAILURE);
}
