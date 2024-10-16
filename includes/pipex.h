/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:19:07 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/18 14:50:11 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define IS_INFILE		0
# define IS_OUTFILE		1
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

/* checks.c*/
void	check_params(int argc, char **argv);
int		open_files(char *file, int class);

/* utils.c */
void	wait_for_children(t_pipex *pipex);
void	close_pipe(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
void	error_exit(char *error);

#endif