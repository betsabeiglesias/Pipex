/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:14 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 14:20:25 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	creat_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		if (pipe(pipex->pipe[i]) < 0)
			free_parent(pipex);
		i++;
	}
}

void	init_pipes(t_pipex *pipex, int num_process)
{
	int	i;
	int	j;

	pipex->pipe = malloc((sizeof(int *) * num_process));
	if (pipex->pipe == NULL)
	{
		close_files(pipex);
		error_exit("Error pipe\n");
	}
	i = 0;
	while (i < num_process)
	{
		pipex->pipe[i] = malloc (sizeof(int) * 2);
		if (pipex->pipe[i] == NULL)
		{
			j = -1;
			while (++j <= i)
				free(pipex->pipe[j]);
			close_files(pipex);
			error_exit("Error pipe\n");
		}
		i++;
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		if (pipex->pipe[i])
		{
			close(pipex->pipe[i][0]);
			close(pipex->pipe[i][1]);
		}
		i++;
	}
}

int	open_files(char *file, int class)
{
	int	infile;
	int	outfile;

	if (class == IS_INFILE)
	{
		infile = open(file, O_RDONLY);
		if (infile < 0)
			error_exit("Error infile\n");
		return (infile);
	}
	else if (class == IS_OUTFILE)
	{
		outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
			error_exit("Error outfile\n");
		return (outfile);
	}
	return (1);
}

void	get_heredoc(char *argv, t_pipex *pipex)
{
	char	*temp;
	int		file;

	file = open(".heredoc_temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file < 0)
		error_exit("her_doc error\n");
	while (1)
	{
		ft_printf("heredoc>");
		temp = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(temp, argv, ft_strlen(argv)))
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, file);
		free(temp);
	}
	close(file);
	pipex->infile = open(".heredoc_temp", O_RDONLY);
	if (pipex->infile < 0)
		error_exit("Infile error\n");
}
