/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:14:40 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:14:42 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dst2;
	char	*src2;

	dst2 = (char*)dst;
	src2 = (char*)src;
	i = (src2 > dst2) ? 0 : (len - 1);
	if (len != 0)
	{
		while (len)
		{
			dst2[i] = src2[i];
			i = (src2 > dst2) ? i + 1 : i - 1;
			len--;
		}
	}
	return (dst2);
}
