/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:14:59 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/18 13:15:17 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

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

void	first_command(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		error_exit("Command not found\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_command(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		error_exit("Command not found\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	check_params(argc, argv);
	pipex.infile = open_files(argv[1], IS_INFILE);
	pipex.outfile = open_files(argv[argc - 1], IS_OUTFILE);
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	if (pipe(pipex.fd) < 0)
		error_exit("error pipe\n");
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		first_command(pipex, argv, envp);
	}
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_command(pipex, argv, envp);
	close_pipe(&pipex);
	wait_for_children(&pipex);
	free_parent(&pipex);
	return (0);
}
