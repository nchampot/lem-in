#include "lem_in.h"

void		preshow(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		ft_putendl(lines[i]);
		i++;
	}
	ft_putchar('\n');
}

int			count_rooms(char **all_rooms)
{
	int	len;

	len = 0;
	while (all_rooms[len])
		len++;
	return (len + 2);
}
