/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:16:50 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:24:26 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*new;
	char	*b;
	size_t	count;

	count = 0;
	new = (char *) src;
	b = (char *) dest;
	if (new == b)
		return (dest);
	while (count < n)
	{
		b[count] = new[count];
		count++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2, int f)
{
	char	*dest;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dest = (char *) ft_calloc((lens1 + lens2 + 1), sizeof(char));
	if (!dest)
		return (0);
	ft_memcpy(dest, s1, lens1);
	i = 0;
	while (lens2 > 0)
	{
		dest[lens1] = s2[i];
		lens2--;
		lens1++;
		i++;
	}
	dest[lens1] = '\0';
	if (f == 1)
		free(s1);
	return (dest);
}
