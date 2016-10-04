/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:18:59 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:19:00 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return (NULL);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = (s) ? s[start + i] : '\0';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
