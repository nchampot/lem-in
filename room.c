#include "lem_in.h"

t_room	new_room(char *name, char status, char **all_links)
{
	t_room	room;

	room.name = name;
	room.status = status;
	room.value = status == END ? 0 : -1;
	room.value = status == START ? 1000 : -1;
	room.doors = get_room_doors(name, all_links);
	room.waiting_ants = 0;
	return (room);
}

static char	*get_link(char *name, char *link)
{
	char	**buf;

	buf = ft_strsplit(link, '-');
	if (!buf[0] || !buf[1] || buf[2])
		exit_pgm("WRONG LINKS");
	if (ft_strcmp(buf[0], name) == 0)
		return (buf[1]);
	if (ft_strcmp(buf[1], name) == 0)
		return (buf[0]);
	return (NULL);
}

char	**get_room_doors(char *name, char **all_links)
{
	char	**doors;
	char	*buf;
	int	i;

	doors = malloc(sizeof(char*));
	*doors = NULL;
	i = 0;
	while (all_links[i])
	{
		if ((buf = get_link(name, all_links[i])))
		{
			ft_addstr(&doors, buf);
			free(buf);
		}
		i++;
	}
	return (doors);
}	

static	int	is_not_in(char *name, char **doors, char *start, char *end)
{
	int	i;

	if (ft_strcmp(end, name) == 0)
		return (0);
	if (ft_strcmp(start, name) == 0)
		return (0);
	i = 0;
	while (doors[i])
	{
		if (ft_strcmp(name, doors[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**get_all_rooms(char **lines, char **all_links, char *start, char *end)
{
	char	**doors;
	int	i;
	char	**buf;

	doors = malloc(sizeof(char*));
	*doors = NULL;
	i = 0;
	while (all_links[i])
	{
		buf = ft_strsplit(all_links[i], '-');
		if (is_not_in(buf[0], doors, start, end) && is_declared(buf[0], lines))
			ft_addstr(&doors, buf[0]);
		if (is_not_in(buf[1], doors, start, end) && is_declared(buf[1], lines))
			ft_addstr(&doors, buf[1]);
		i++;
	}
	return (doors);
}
