#include "lem_in.h"

void	exit_pgm(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	compare_val(int tmp_door, int best_door)
{
	char	status;
	char	best_status;
	int		value;
	int		best_val;

	status = g_anthill[tmp_door].status;
	value = g_anthill[tmp_door].value;
	if (best_door != -1)
	{
		best_val = g_anthill[best_door].value + g_anthill[best_door].waiting_ants;
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

int			count_rooms(char **all_rooms)
{
	int	len;

	len = 0;
	while (all_rooms[len])
		len++;
	return (len + 2);
}
