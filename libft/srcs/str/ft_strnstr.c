/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:59:54 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:08:48 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** The `ft_strnstr()` function locates the first occurence of the null-termi-
** nated string `s2` in the string `s1`, where not more than `n` characters
** are searched. Searching for '\0' always succeeds (if `s2` is empty).
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (*s1 && len_s2 <= n--)
	{
		if (!ft_memcmp(s1++, s2, len_s2))
			return ((char*)s1 - 1);
	}
	return (NULL);
}
