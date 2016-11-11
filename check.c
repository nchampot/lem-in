/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:10:25 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/11 15:23:07 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check(void)
{
	int	start_index;
	int	i;
	int	j;
	int	door_index;

	start_index = 0;
	while (g_anthill[start_index].status != START)
		start_index++;
	i = 0;
	while (i < start_index)
	{
		j = 0;
		while (g_anthill[i].doors[j])
		{
			door_index = get_index(g_anthill[i].doors[j]);
			if (door_index == start_index && g_anthill[i].value != -1)
				return (1);
			j++;
		}
		i++;
	}
	exit_pgm("ERROR: The end is unattainable.");
	return (0);
}

int		is_declared(char *room, char **lines)
{
	int		i;
	char	**buf;

	i = 1;
	while (lines[i])
	{
		buf = ft_strsplit(lines[i], ' ');
		if (buf[0] && is_int(buf[1]) != -1 && is_int(buf[2]) != -1 && !buf[3])
			if (ft_strcmp(buf[0], room) == 0)
				return (1);
		free_2d(buf);
		i++;
	}
	return (0);
}

int		is_valid(char *line)
{
	char	**buff;
	char	**bufff;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	buff = ft_strsplit(line, '-');
	bufff = ft_strsplit(line, ' ');
	while (buff[i])
		i++;
	while (bufff[i2])
		i2++;
	if (line[0] == '#')
		return (1);
	if (i == 2 && buff[0][0] != 'L' && buff[1][0] != 'L')
		return (1);
	if (i2 == 3 && bufff[0][0] != 'L' && is_int(bufff[1]) != -1\
			&& is_int(bufff[2]) != -1)
		return (1);
	return (0);
}

char	**get_all_links(char **lines)
{
	char	**links;
	int		i;

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
