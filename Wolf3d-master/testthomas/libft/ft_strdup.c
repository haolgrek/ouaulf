/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:16:40 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:16:42 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s1)
{
	char *s2;

	s2 = malloc(sizeof(*s1) * ft_strlen(s1) + 1);
	if (s2)
		return (ft_strcpy(s2, s1));
	return (NULL);
}
