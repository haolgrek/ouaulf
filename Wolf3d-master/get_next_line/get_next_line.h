/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:55:44 by tandrieu          #+#    #+#             */
/*   Updated: 2016/02/17 14:29:15 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int						get_next_line(const int fd, char **line);

typedef struct			s_backup
{
	char	*data;
	int		fd;
}						t_backup;

#endif
