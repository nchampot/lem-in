#include "lem_in.h"
#include <stdio.h>

void	exit_pgm(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	compare_val(int door_index, int best_door)
{
	char	status;
	char	best_status;
	int		value;
	int		best_val;

	status = g_anthill[door_index].status;
	value = g_anthill[door_index].value;
	if (best_door != -1)
	{
		best_val = g_anthill[best_door].value;
		best_status = g_anthill[best_door].status;
	}
	else
		best_val = 100000;
	if (value != -1 && value <= best_val && status != START)
	{
		if (value == best_val)
		{
			if (best_status == OCCUPIED && status == FREE)
				return (1);
			return (0);
		}
		return (1);
	}
	return (0);
}
