/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:29:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/11 15:29:53 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/inc/libft.h"

# define BUF_SIZE		1
# define SPILL_MULT		2
# define MAX_FD			1000

typedef struct		s_stock
{
	char			*spill;
	long			length;
	long			lu;
	int				read_ret;
	char			*line_end;
}					t_stock;

int					get_next_line(int fd, char **line);

#endif
