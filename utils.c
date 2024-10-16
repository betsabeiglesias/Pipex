/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:10:26 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/18 12:58:12 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	wait_for_children(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	free_child(t_pipex *pipex)
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

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	error_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
