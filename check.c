#include "lem_in.h"

int	check(void)
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

int	is_declared(char *room, char **lines)
{
	int	i;
	char	**buf;

	i = 1;
	while (lines[i])
	{
		buf = ft_strsplit(lines[i], ' ');
		if (buf[0] && is_int(buf[1]) && is_int(buf[2]) && !buf[3])
			if (ft_strcmp(buf[0], room) == 0)
				return (1);
		free_2d(buf);
		i++;
	}
	return (0);
}
