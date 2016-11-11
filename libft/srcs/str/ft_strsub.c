/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:00:08 by nchampot          #+#    #+#             */
/*   Updated: 2016/07/19 12:09:25 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** The `ft_strsub()` function takes a part of the string `s` (starting at index
** `start`, for `len` characters), creates a new string out of this substracted
** part, and returns a pointer to it. The function returns NULL if the memory
** allocation failed. If `start` and/or `len` do not designate correct portions
** of `s`, behavior is undefined (we return NULL here).
** If `start` is outside `s`'s boundaries, do nothing (return NULL).
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;
	char	*new_str;

	len_str = ft_strlen(s);
	if (start > len_str || len > len_str)
		return (NULL);
	if (start + len > len_str)
		return (NULL);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	new_str = ft_strncpy(new_str, s + start, len);
	new_str[len] = '\0';
	return (new_str);
}
