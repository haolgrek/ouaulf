/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:15:50 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:15:51 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define BUF_SIZE 999999999

char	**ft_read(int fd, char c)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	tab = ft_strsplit(buf, c);
	return (tab);
}
