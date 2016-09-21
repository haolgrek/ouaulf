/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:14:05 by amaindro          #+#    #+#             */
/*   Updated: 2016/01/14 16:47:56 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int						get_next_line(const int fd, char **line);

typedef struct			s_backup
{
	char	*data;
	int		fd;
}						t_backup;

#endif
