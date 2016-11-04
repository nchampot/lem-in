/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:47:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/04 17:01:36 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

char		**get_data(char *filename)
{
	char	*buf;
	int	fd;
	char	**lines;

	fd = filename ? open(filename, O_RDONLY) : 0;
	lines = malloc(sizeof(char*));
	*lines = NULL;
	get_next_line(fd, &buf);
	if (is_int(buf) == 1)
		ft_addstr(&lines, buf);
	else
		exit_pgm("ERROR: The number of ants is not valid or not defined (must be on the first line)");
	while (get_next_line(fd, &buf) && *buf != '\0')
	{
		if (!is_valid(buf))
			break;
		ft_addstr(&lines, buf);
	}
	return (lines);
}

static char	*get_start(char **lines)
{
	int	i;
	char	**buff;

	i = 1;
	while (lines[i])
	{
		if (ft_strcmp(lines[i], "##start") == 0 && lines[i + 1])
		{
			buff = ft_strsplit(lines[i + 1], ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##start (name coordx coordy)");
			return (buff[0]);
		}
		i++;
	}
	exit_pgm("ERROR: The ##start is not valid or not defined");
	return (0);
}

static char	*get_end(char **lines)
{
	char	**buff;
	int		i;
	
	i = 1;
	while (lines[i])
	{
		if (ft_strcmp(lines[i], "##end") == 0 && lines[i + 1])
		{
			buff = ft_strsplit(lines[i + 1], ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##end (name coordx coordy)");
			return (buff[0]);
		}
		i++;
	}
	exit_pgm("ERROR: The ##end is not valied or not defined");
	return (0);
}

static char	**get_all_links(char **lines)
{
	char	**links;
	int	i;

	i = 1;
	links = malloc(sizeof(char *));
	*links = NULL;
	while (lines[i])
	{
		if (ft_strchr(lines[i], '-'))
			ft_addstr(&links, lines[i]);
		i++;
	}
	return (links);
}

static t_room	*create(char *start, char *end, char **all_links, char **all_rooms)
{
	t_room		*anthill;
	int			i;
	
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

t_room		*create_anthill(char **lines)
{
	char		**all_links;
	char		**all_rooms;
	char		*start;
	char		*end;
	
	start = get_start(lines);
	end = get_end(lines);
	all_links = get_all_links(lines);
	all_rooms = get_all_rooms(lines, all_links, start, end);
	if (is_enough_data(start, end, all_links, all_rooms))
		return (create(start, end, all_links, all_rooms));
	exit_pgm("ERROR: Not enough data to build a decent anthill");
	return (NULL);
}
