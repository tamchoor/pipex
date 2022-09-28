/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:39:06 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:43:59 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_cheak_envp(char **envp)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (n != 0)
	{
		if (!envp[i])
		{
			return (-1);
		}
		n = ft_strncmp(envp[i], "PATH", 4);
		i++;
	}
	i--;
	return (i);
}

void	ft_printstr(char *str, int fd)
{
	int	count;

	count = ft_strlen(str);
	write(fd, str, count);
}

void	ft_errors1(void)
{
	perror("Error ");
	exit (EXIT_FAILURE);
}

void	ft_errors(int e)
{
	if (e == 0)
		ft_printstr("Error format || envp.\n", 2);
	else if (e == 1)
		ft_printstr("Error cmd.\n", 2);
	else if (e == 2)
		ft_printstr("Error envp.\n", 2);
	else if (e == 3)
		ft_printstr("Error open infile.\n", 2);
	else if (e == 5)
		ft_printstr("Error execve.\n", 2);
	exit (EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register unsigned char	u1;
	register unsigned char	u2;

	while (n-- > 0)
	{
		u1 = (unsigned char) *s1++;
		u2 = (unsigned char) *s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}
