#include "lem_in.h"
#include <fcntl.h>

void		preshow(char *filename)
{
	char	*buf;
	int	fd;
	int	ret;

	buf = malloc(30000);
	fd = open(filename, O_RDONLY);
	ret = read(fd, buf, 30000);
	buf[ret] = '\0';
	ft_putendl(buf);
}

int			count_rooms(char **all_rooms)
{
	int	len;

	len = 0;
	while (all_rooms[len])
		len++;
	return (len + 2);
}
