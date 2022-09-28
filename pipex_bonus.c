/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:55:17 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:47:09 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		free(cmd);
		ft_errors(1);
	}
	ex = execve(path, cmd, envp);
	if (ex == -1)
	{
		free(cmd);
		free(path);
		ft_errors1();
	}
}

void	ft_pipex(int i, char **argv, char **envp, int l)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		ft_errors1();
	pid = fork();
	if (pid < 0)
		ft_errors1();
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			ft_errors1();
		find_cmd(argv[i], envp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) < 0)
			ft_errors1();
		if (i == l - 1)
			find_cmd(argv[l], envp);
		if (waitpid(pid, NULL, 0) < 0)
			ft_errors1();
	}
}

void	ft_itshere_doc(t_pipe **spipe, char **argv, int argc)
{
	char	*line;
	int		d;

	if (pipe((**spipe).fd) < 0)
		ft_errors1();
	(**spipe).hd = 1;
	d = 5;
	while (d != 0)
	{
		write(1, "pipe heredoc>", 13);
		if (get_next_line(&line) == -1)
			ft_errors(2);
		d = ft_strncmp(argv[2], line, ft_strlen(argv[2]));
		write((**spipe).fd[1], line, ft_strlen(line));
		free(line);
	}
	if (dup2((**spipe).fd[0], STDIN_FILENO) < 0)
		ft_errors1();
	close((**spipe).fd[1]);
	(**spipe).outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND);
	if ((**spipe).outfile == -1)
		ft_errors1();
}

void	ft_openfiles(t_pipe *spipe, char **argv, int argc)
{
	(*spipe).hd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		ft_itshere_doc(&spipe, argv, argc);
	else
	{
		(*spipe).outfile = open(argv[argc - 1], O_CREAT
				| O_WRONLY | O_TRUNC, 0777);
		if ((*spipe).outfile == -1)
			ft_errors1();
		if (access(argv[1], F_OK | R_OK) < 0)
			ft_errors1();
		(*spipe).infile = open(argv[1], O_RDONLY);
		if ((*spipe).infile == -1)
			ft_errors1();
		if (dup2((*spipe).infile, STDIN_FILENO) < 0)
			ft_errors1();
	}
	if (dup2((*spipe).outfile, STDOUT_FILENO) < 0)
		ft_errors1();
}

int	main(int argc, char **argv, char **envp)
{
	int		f;
	int		l;
	t_pipe	spipe;

	if (argc < 5)
		ft_errors(0);
	ft_openfiles(&spipe, argv, argc);
	f = 3 + spipe.hd - 1;
	l = argc - 1 - 1;
	while (f < l)
	{
		ft_pipex(f, argv, envp, l);
		f++;
	}
	if (spipe.hd == 0)
		close (spipe.infile);
	else
		close(spipe.fd[0]);
	close (spipe.outfile);
	return (0);
}
