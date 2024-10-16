/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:16:17 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/18 13:23:56 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	check_params(int argc, char **argv)
{
	int	i;

	if (argc != 5)
		error_exit("Incorrect arguments\n");
	i = -1;
	while (++i < argc - 1)
	{
		if (ft_strlen(argv[i]) == 0)
			error_exit("Incorrect arguments\n");
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
	else
	{
		outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
			error_exit("Error outfile\n");
		return (outfile);
	}
}
