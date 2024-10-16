/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:05:06 by betsabe           #+#    #+#             */
/*   Updated: 2024/05/18 14:49:49 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		**pipe;
	int		infile;
	int		outfile;
	int		here_doc;
	int		nb_cmd;
	int		idx_process;
	char	*path;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
	pid_t	pid;
}	t_pipex;
/* pipex_bonus.h */
void	do_child_process(char **argv, char **envp, t_pipex pipex);
void	execute(char *cmd, char **envp, t_pipex pipex);
/* utils_bonus.c */
void	close_notused(t_pipex *pipex);
void	check_params(int argc, char **argv, t_pipex *pipex);
char	*find_path(char **env);
char	*get_command(char **path, char *cmd);
void	error_exit(char *error);
/* utils2_bonus.c */
void	creat_pipes(t_pipex *pipex);
void	init_pipes(t_pipex *pipex, int num_process);
void	close_pipes(t_pipex *pipex);
int		open_files(char *file, int class);
void	get_heredoc(char *argv, t_pipex *pipex);
/* free_bonus.c */
void	close_files(t_pipex *pipex);
void	free_path(t_pipex *pipex);
void	free_args(t_pipex *pipex);
void	free_errorcmd(t_pipex *pipex);
void	child_free(t_pipex *pipex);
/* free2_bonus.c */
void	free_pipes(int **pipe, int num_process);
void	free_errorpath(t_pipex *pipex);
void	free_errorargs(t_pipex *pipex);
void	free_parent(t_pipex *pipex);

#endif