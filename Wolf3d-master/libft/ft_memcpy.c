/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:14:28 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:14:30 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	char		*str2;

	i = 0;
	str = (char*)dst;
	str2 = (char*)src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (dst);
}
