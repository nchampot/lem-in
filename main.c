/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:32:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/10/12 16:07:24 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	main(int ac, char **av)
{
	t_room	start;

	if (ac == 2)
		start = read_file(av[1]);
	path_finder();
	anthill_team_crossing();
	return (1);
}
