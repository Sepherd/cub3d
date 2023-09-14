/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:42:41 by arecce            #+#    #+#             */
/*   Updated: 2022/03/25 22:42:56 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len-- >= i)
	{
		if ((*haystack == *needle) && ft_memcmp(haystack, needle, i) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
