/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:17:39 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:17:41 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(dst);
	while (i < n && src[i] != '\0')
	{
		dst[i + end] = src[i];
		i++;
	}
	dst[i + end] = '\0';
	return (dst);
}
