/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:13:13 by arecce            #+#    #+#             */
/*   Updated: 2022/03/22 12:58:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*us1;
	unsigned const char	*us2;

	i = 0;
	us1 = s1;
	us2 = s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
		{
			return (us1[i] - us2[i]);
		}
	i++;
	}
	return (0);
}
