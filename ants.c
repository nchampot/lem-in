/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:47:48 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 16:07:22 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int			get_nb_ants(char *filename)
{
	char	*buf;
	int	fd;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &buf);
	return (ft_atoi(buf));
}

int			*init_ants(int nb_ants)
{
	int	start_index;
	int	i;
	int	*ants;

	ants = malloc(sizeof(int) * nb_ants);
	start_index = 0;
	i = 0;
	while (g_anthill[start_index].status != START)
		start_index++;
	i = -1;
	while (++i < nb_ants)
		ants[i] = start_index;
	return (ants);
}

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

static void	show_the_move(int ant, char *door)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(door);
	ft_putchar(' ');
}

void		unleash_the_ants(int *ants, int nb_ants)
{
	int	i;
	int	runners;
	int	j;
	int	buf;

	runners = nb_ants;
	j = 0;
	while (runners)
	{
		i = -1;
		while (++i < nb_ants)
		{
			if (ants[i] != 0)
			{
				buf = ants[i];
				if ((ants[i] = run(ants[i])) == 0)
					runners--;
				if (buf != ants[i])
					show_the_move(i + 1, g_anthill[ants[i]].name);
			}
		}
		ft_putchar('\n');
	}
}
