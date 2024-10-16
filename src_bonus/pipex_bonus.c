/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:48:37 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 14:37:17 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	check_params(argc, argv, &pipex);
	if (pipex.here_doc == 1)
		get_heredoc(argv[2], &pipex);
	else
		pipex.infile = open_files(argv[1], IS_INFILE);
	pipex.outfile = open_files(argv[argc - 1], IS_OUTFILE);
	pipex.nb_cmd = argc - 3 - pipex.here_doc;
	init_pipes(&pipex, pipex.nb_cmd - 1);
	creat_pipes(&pipex);
	pipex.idx_process = -1;
	while (++(pipex.idx_process) < pipex.nb_cmd)
		do_child_process(argv, envp, pipex);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
}

void	do_child_process(char **argv, char **envp, t_pipex pipex)
{
	pipex.pid = fork();
	if (pipex.pid == 0)
	{
		if (pipex.idx_process == 0)
		{
			dup2(pipex.infile, STDIN_FILENO);
			dup2(pipex.pipe[pipex.idx_process][1], STDOUT_FILENO);
		}
		else if (pipex.idx_process == pipex.nb_cmd - 1)
		{
			dup2(pipex.pipe[pipex.idx_process - 1][0], STDIN_FILENO);
			dup2(pipex.outfile, STDOUT_FILENO);
		}
		else
		{
			dup2(pipex.pipe[pipex.idx_process - 1][0], STDIN_FILENO);
			dup2(pipex.pipe[pipex.idx_process][1], STDOUT_FILENO);
		}
		close_notused(&pipex);
		execute(argv[pipex.idx_process + 2 + pipex.here_doc], envp, pipex);
	}
}

void	execute(char *cmd, char **envp, t_pipex pipex)
{
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	if (!pipex.cmd_path)
		free_errorpath(&pipex);
	pipex.cmd_args = ft_split(cmd, ' ');
	if (!pipex.cmd_args)
		free_errorargs(&pipex);
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_errorcmd(&pipex);
		error_exit("Command not found\n");
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
	{
		child_free(&pipex);
		error_exit("Command failed\n");
	}
}
