#include "lem_in.h"

void	exit_pgm(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	free_2d(char **stuff)
{
	int		i;

	i = -1;
	while (stuff[++i])
		free(stuff[i]);
	free(stuff);
}

int	is_enough_data(char *start, char *end, char **all_links, char **all_rooms)
{
	if (!start || !end || !all_links || !all_rooms)
		return (0);
	return (1);
}

int	compare_val(int tmp_door, int best_door)
{
	char	status;
	char	best_status;
	int		value;
	int		best_val;

	status = g_anthill[tmp_door].status;
	value = g_anthill[tmp_door].value + g_anthill[tmp_door].waiting_ants;
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

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i >= 10)
		return (0);
	return (1);
}
