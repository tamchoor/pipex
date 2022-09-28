/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:55:22 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:22:52 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipe
{
	int		hd;
	int		infile;
	int		outfile;
	int		fd[2];

}		t_pipe;

void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2, int f);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_next_line(char **line1);
void	ft_errors(int e);
void	ft_errors1(void);
void	ft_printstr(char *str, int fd);
void	find_cmd(char *argv, char **envp);
char	*ft_path(char *cmd, char **envp);
int		ft_cheak_envp(char **envp);

#endif