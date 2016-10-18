#include "lem_in.h"

static int	get_index(char *name)
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
		if (g_anthill[next_index].value == -1)
			init_rooms_value(next_index, value + 1);
		i++;
	}
}

static int	move(int ant_index, int best_door)
{
	char	status;
	int	door_index;

	door_index = get_index(g_anthill[ant_index].doors[best_door]);
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
	int	best_val;
	int	door_index;
	int	best_door;
	int	i;
	char	*door;

	i = 0;
	best_val = 100000;
	while ((door = g_anthill[ant_index].doors[i]))
	{
		if ((door_index = get_index(door)) == 0)
		{
			best_door = i;
			best_val = 666;
			break;
		}
		if (g_anthill[door_index].value != -1 &&\
			g_anthill[door_index].value <= best_val &&\
			g_anthill[door_index].status != START)
		{
			best_val = g_anthill[door_index].value;;
			best_door = i;
		}
		i++;
	}
	if (g_anthill[get_index(g_anthill[ant_index].doors[best_door])].status == OCCUPIED)
		return (ant_index);
	return (best_val != 100000 ? move(ant_index, best_door) : ant_index);
}
