/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:36:20 by tamchoor          #+#    #+#             */
/*   Updated: 2021/12/27 13:31:00 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
