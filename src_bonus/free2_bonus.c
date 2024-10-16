/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:14 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 14:37:32 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipes(int **pipe, int num_process)
{
	int	i;

	i = 0;
	while (i < num_process)
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
}

void	free_errorpath(t_pipex *pipex)
{
	close_files(pipex);
	close_pipes(pipex);
	free_pipes(pipex->pipe, pipex->nb_cmd - 1);
	error_exit("Error envP");
}

void	free_errorargs(t_pipex *pipex)
{
	close_files(pipex);
	close_pipes(pipex);
	free_pipes(pipex->pipe, pipex->nb_cmd - 1);
	free_path(pipex);
	error_exit("Error envP");
}

void	free_parent(t_pipex *pipex)
{
	close_files(pipex);
	free_pipes(pipex->pipe, pipex->nb_cmd - 1);
}
