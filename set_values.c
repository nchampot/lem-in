#include "lem_in.h"

int		get_index(char *name)
{
	int	i;

	i = 0;
	while (g_anthill[i - 1].status != START)
	{
		if (ft_strcmp(g_anthill[i].name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	init_rooms_value(int curr_index, int value)
{
	int	i;
	int	next_index;

	i = 0;
	g_anthill[curr_index].value = value;
	while (g_anthill[curr_index].doors[i])
	{
		next_index = get_index(g_anthill[curr_index].doors[i]);
		if (g_anthill[next_index].value == -1 || (g_anthill[next_index].value > value + 1 &&\
			g_anthill[next_index].status != END && g_anthill[next_index].status != START))
			init_rooms_value(next_index, value + 1);
		i++;
	}
}

static int	move(int ant_index, int door_index)
{
	char	status;

	if (g_anthill[ant_index].status != START)
	{
		g_anthill[ant_index].status = FREE;
		g_anthill[ant_index].value--;
	}
	if (g_anthill[door_index].status != END)
	{
		g_anthill[door_index].status = OCCUPIED;
		g_anthill[door_index].value++;
	}
	return (door_index);
}

int	run(int ant_index)
{
	int	door_index;
	int	best_door;
	int	i;
	char	*door;

	i = 0;
	best_door = -1;
	while ((door = g_anthill[ant_index].doors[i]))
	{
		if ((door_index = get_index(door)) == 0)
		{
			best_door = door_index;
			break;
		}
		if (compare_val(door_index, best_door))
			best_door = door_index;
		i++;
	}
	if (best_door != -1 && g_anthill[best_door].status == OCCUPIED)
		return (ant_index);
	return (best_door != -1 ? move(ant_index, best_door) : ant_index);
}
