/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:33:44 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/11 15:42:36 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** ROOM STATUS
*/
# define START 's'
# define END 'e'
# define FREE 'f'
# define OCCUPIED 'o'

/*
** COLORS
*/
# define START 's'
# define END 'e'
# define FREE 'f'
# define OCCUPIED 'o'

# include <stdlib.h>
# include "libft/inc/libft.h"
# include "get_next_line.h"

typedef struct	s_room
{
	char		*name;
	char		status;
	char		**doors;
	int			value;
	int			waiting_ants;
}				t_room;

t_room			*g_anthill;

char			**get_all_links(char **lines);
int				is_valid(char *line);
char			**get_data(char *filename);
int				is_declared(char *room, char **lines);
int				is_int(char *str);
int				check(void);
int				is_enough_data(char *s, char *e, char **l, char **r);
void			free_2d(char **stuff);
int				*init_ants(int nb_ants);
int				get_index(char *name);
int				compare_val(int curr_door, int best_door);
void			preshow(char **lines);
int				run(int ant_index);
void			unleash_the_ants(int *ants, int nb_ants);
void			init_rooms_value(int curr_index, int value);
char			**get_room_doors(char *name, char **all_links);
t_room			*create_anthill(char **filename);
char			**get_all_rooms(char **li, char **l, char *start, char *end);
void			exit_pgm(char *msg);
int				count_rooms(char **all_rooms);
t_room			new_room(char *name, char status, char **all_links);

#endif
