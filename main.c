/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:32:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/11/11 15:07:00 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	int		*ants;
	int		nb_ants;
	char	**data;

	data = get_data(av[1]);
	g_anthill = create_anthill(data);
	init_rooms_value(0, 0);
	check();
	nb_ants = ft_atoi(*data);
	preshow(data);
	ants = init_ants(nb_ants);
	unleash_the_ants(ants, nb_ants);
	return (1);
}
