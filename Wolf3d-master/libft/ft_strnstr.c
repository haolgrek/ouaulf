/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:18:31 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:18:33 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i + j <= n)
	{
		if (s2[j] == '\0')
			return ((char*)&s1[i]);
		if (s1[i + j] == s2[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
