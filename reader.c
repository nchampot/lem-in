/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:47:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 16:07:22 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static char	*get_start(char *filename)
{
	char	*buf;
	char	**buff;
	int	fd;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		if (ft_strcmp(buf, "##start") == 0)
		{
			get_next_line(fd, &buf);
			buff = ft_strsplit(buf, ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##start (name coordx coordy)");
			return (buff[0]);
		}
	}
	exit_pgm("ERROR: The ##start is not defined");
	return (0);
}

static char	*get_end(char *filename)
{
	char	*buf;
	char	**buff;
	int		fd;
	
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		if (ft_strcmp(buf, "##end") == 0)
		{
			get_next_line(fd, &buf);
			buff = ft_strsplit(buf, ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##end (name coordx coordy)");
			return (buff[0]);
		}
	}
	exit_pgm("ERROR: The ##end is not defined");
	return (0);
}

static char	**get_all_links(char *filename)
{
	char	*buf;
	char	**links;
	int		fd;

	fd = open(filename, O_RDONLY);
	links = malloc(sizeof(char *));
	*links = NULL;
	while (get_next_line(fd, &buf))
	{
		if (ft_strchr(buf, '-'))
			ft_addstr(&links, buf);
	}
	return (links);
}

t_room		*create_anthill(char *filename)
{
	t_room		*anthill;
	char		**all_links;
	char		**all_rooms;
	char		*start;
	char		*end;
	int			i;
	
	start = get_start(filename);
	end = get_end(filename);
	all_links = get_all_links(filename);
	all_rooms = get_all_rooms(all_links, start, end);
	anthill = (t_room *)malloc(sizeof(t_room) * count_rooms(all_rooms));
	*anthill = new_room(end, END, all_links);
	i = 0;
	while (all_rooms[i])
	{
		anthill[i + 1] = new_room(all_rooms[i], FREE, all_links);
		i++;
	}
	anthill[i + 1] = new_room(start, START, all_links);
	return (anthill);
} 

int			get_nb_ants(char *filename)
{
	char	*buf;
	int	fd;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &buf);
	return (ft_atoi(buf));
}
