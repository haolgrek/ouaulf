/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:17:30 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:17:32 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s2)
	{
		while (s[i] != '\0')
		{
			s2[i] = f(s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
