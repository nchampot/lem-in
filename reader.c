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

static char		**get_lines(char *filename)
{
	char	*buf;
	char	**buff;
	char	**bufff;
	int	fd;
	char	**lines;

	fd = open(filename, O_RDONLY);
	lines = malloc(sizeof(char*));
	*lines = NULL;
	while (get_next_line(fd, &buf))
	{
		buff = ft_strsplit(buf, '-');
		bufff = ft_strsplit(buf, ' ');
		if (buf[0] == '#')
			ft_addstr(&lines, buf);
		else if (is_int(buf))
			ft_addstr(&lines, buf);
		else if (buff[0] && buff[1] && !buff[2])
			ft_addstr(&lines, buf);
		else if (bufff[0] && bufff[1] && bufff[2] && !bufff[3])
			ft_addstr(&lines, buf);
		free_2d(buff);
		free_2d(bufff);
	}
	return (lines);
}

static char	*get_start(char **lines)
{
	int	i;
	char	**buff;

	i = 0;
	while (lines[i])
	{
		if (ft_strcmp(lines[i], "##start") == 0)
		{
			buff = ft_strsplit(lines[i + 1], ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##start (name coordx coordy)");
			return (buff[0]);
		}
		i++;
	}
	exit_pgm("ERROR: The ##start is not defined");
	return (0);
}

static char	*get_end(char **lines)
{
	char	**buff;
	int		i;
	
	i = 0;
	while (lines[i])
	{
		if (ft_strcmp(lines[i], "##end") == 0)
		{
			buff = ft_strsplit(lines[i + 1], ' ');
			if (!buff[0] || !buff[1] || !buff[2])
				exit_pgm("ERROR: Wrong format passed to ##end (name coordx coordy)");
			return (buff[0]);
		}
		i++;
	}
	exit_pgm("ERROR: The ##end is not defined");
	return (0);
}

static char	**get_all_links(char **lines)
{
	char	**links;
	int	i;

	i = 0;
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

t_room		*create_anthill(char *filename)
{
	char		**all_links;
	char		**all_rooms;
	char		*start;
	char		*end;
	char		**lines;
	
	lines = get_lines(filename);
	start = get_start(lines);
	end = get_end(lines);
	all_links = get_all_links(lines);
	all_rooms = get_all_rooms(all_links, start, end);
	if (is_enough_data(start, end, all_links, all_rooms))
		return (create(start, end, all_links, all_rooms));
	exit_pgm("ERROR: Not enough data to build a decent anthill");
	return (NULL);
}
