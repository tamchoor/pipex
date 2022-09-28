/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:04:34 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:42:41 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_pathes(char **envp)
{
	char	**paths;
	int		i;

	i = ft_cheak_envp(envp);
	if (envp[i] == 0)
		ft_errors(1);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

void	ft_free_split(char ***s)
{
	int	i;

	i = 0;
	if (*s != NULL)
	{
		while ((*s)[i])
			free((*s)[i++]);
		free((*s));
	}
}

char	*ft_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path;
	int		i;

	all_paths = get_pathes(envp);
	i = 0;
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], "/", 0);
		path = ft_strjoin(path, cmd, 1);
		if (access(path, X_OK) == 0)
		{
			ft_free_split(&all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	i = 0;
	ft_free_split(&all_paths);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	return (NULL);
}
