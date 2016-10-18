/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:33:44 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 16:07:21 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

/*
** ROOM STATUS
*/
# define START 's'
# define END 'e'
# define FREE 'f'
# define OCCUPIED 'o'

#include <stdlib.h>
#include <unistd.h>
#include "libft/inc/libft.h"
#include "get_next_line.h"

typedef struct	s_room
{
	char		*name;
	char		status;
	char		**doors;
	int		value;
}		t_room;

char	**get_room_doors(char *name, char **all_links);
t_room	*create_anthill(char *filename);
char	**get_all_rooms(char **all_links, char *start, char *end);
void	exit_pgm(char *msg);
t_room	new_room(char *name, char status, char **all_links);

#endif
