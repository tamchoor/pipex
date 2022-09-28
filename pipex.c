/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:55:19 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:32:27 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		ex;

	cmd = ft_split(argv, ' ');
	if (cmd == NULL)
		ft_errors(1);
	path = ft_path(cmd[0], envp);
	if (path == NULL)
	{
		ex = 0;
		while (cmd[ex])
			free(cmd[ex++]);
		ft_errors(1);
	}
	ex = execve(path, cmd, envp);
	if (ex == -1)
	{
		ex = 0;
		while (cmd[ex])
		{
			free(cmd[ex++]);
		}
		ft_errors1();
	}
}

void	ft_parent(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		ft_errors1();
	if (dup2(fd[0], STDIN_FILENO) < 0)
		ft_errors1();
	close(fd[1]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		ft_errors1();
	find_cmd(argv[3], envp);
}

void	ft_child(int *fd, char **argv, char **envp)
{
	int	infile;

	if (access(argv[1], F_OK | R_OK) < 0)
		ft_errors1();
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		ft_errors1();
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		ft_errors1();
	close(fd[0]);
	if (dup2(infile, STDIN_FILENO) < 0)
		ft_errors1();
	find_cmd(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	cpid;
	pid_t	w;

	if (argc != 5 || ft_cheak_envp(envp) == -1)
		ft_errors(0);
	if (pipe(fd) == -1)
		ft_errors1();
	cpid = fork();
	if (cpid == -1)
		ft_errors1();
	if (cpid == 0)
	{
		ft_child(fd, argv, envp);
	}
	else
	{
		ft_parent(fd, argv, envp);
		w = waitpid(cpid, NULL, 0);
		close(fd[0]);
		close(fd[1]);
		if (w == -1)
			ft_errors1();
	}
	return (0);
}
