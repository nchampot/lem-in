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

int	main(int ac, char **av)
{
	t_room	*anthill;
	int	i;
	int	j;

	if (ac == 2)
		anthill = create_anthill(av[1]);
	i = 0;
	while (anthill[i].status != END)
	{
		ft_putstr(anthill[i].name);
		ft_putstr(" : ");
		j = 0;
		while (anthill[i].doors[j])
		{
			ft_putstr(anthill[i].doors[j]);
			ft_putstr(" ");
			j++;
		}
		i++;
		ft_putstr("\n");
	} 
	return (1);
}
