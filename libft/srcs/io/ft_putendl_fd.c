#include <unistd.h>
#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		count;

	count = 0;
	count += ft_putstr_fd(s, fd);
	count += ft_putchar_fd('\n', fd);
	return (count);
}

int		ft_putendl(char const *s)
{
	return (ft_putendl_fd(s, STDOUT_FILENO));
}

int		ft_putendl_color(char const *s, char const *c)
{
	ft_putstr(c);
	ft_putstr(s);
	return (ft_putendl(RESET));
}
