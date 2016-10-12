/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:33:44 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 16:07:21 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM-IN_H
#define LEM-IN_H

typedef struct	s_room
{
				char	*name;
				int		value; //nb_of_links_before_end
				char	stat; //start, end, empty, full
				t_room	*linked_rooms;
}				t_room;

#endif
