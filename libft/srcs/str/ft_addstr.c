/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:58:14 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:05:44 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_addstr(char ***tab, const char *s)
{
	int		i;
	char	**new;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((*tab)[i])
		i++;
	new = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while ((*tab)[i])
	{
		new[i] = (*tab)[i];
		i++;
	}
	new[i] = ft_strdup(s);
	i++;
	new[i] = NULL;
	*tab = new;
	return (*tab);
}
