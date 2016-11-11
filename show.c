/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:28:46 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/11 15:28:49 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		preshow(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == '#' && lines[i][1] != '#')
			ft_putendl_color(lines[i], CYN);
		else if (ft_strcmp(lines[i], "##start") == 0)
			ft_putendl_color(lines[i], GRN);
		else if (ft_strcmp(lines[i], "##end") == 0)
			ft_putendl_color(lines[i], RED);
		else
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
