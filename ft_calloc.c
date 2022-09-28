/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:36:20 by tamchoor          #+#    #+#             */
/*   Updated: 2021/10/07 14:36:23 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	char	*new;
	size_t	count;

	new = b;
	count = 0;
	while (count < len)
	{
		new[count] = c;
		count++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	void	*addr;

	num = count * size;
	addr = malloc(num);
	if (addr)
	{
		ft_memset(addr, 0, num);
	}
	return (addr);
}
