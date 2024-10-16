/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:14 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 12:34:00 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_files(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_temp");
}

void	free_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	free_args(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
}

void	free_errorcmd(t_pipex *pipex)
{
	free_path(pipex);
	free_args(pipex);
	free_pipes(pipex->pipe, pipex->nb_cmd - 1);
	close_files(pipex);
}

void	child_free(t_pipex *pipex)
{
	free_path(pipex);
	free_args(pipex);
	free_pipes(pipex->pipe, pipex->nb_cmd - 1);
	free(pipex->cmd);
	close_pipes(pipex);
	close_files(pipex);
}
