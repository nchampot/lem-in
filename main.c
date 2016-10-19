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

#include "lem_in.h"

int		main(int ac, char **av)
{
	int	*ants;
	int	nb_ants;

	g_anthill = create_anthill(av[1]);
	init_rooms_value(0, 0);
	nb_ants = get_nb_ants(av[1]);
	ants = init_ants(nb_ants);
	preshow(av[1]);
	unleash_the_ants(ants, nb_ants);
	return (1);
}
