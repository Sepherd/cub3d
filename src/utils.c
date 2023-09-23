/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:04:06 by arecce            #+#    #+#             */
/*   Updated: 2023/09/23 17:08:07 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_perror(char *msg)
{
	ft_printf("Error\n");
	ft_printf("\033[1;31m%s\033[1;0m\n", msg);
	exit(0);
	return (0);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	// char	*d;
	// char	*s;

	// *d = dst;
	// *s = src;
	while (len > 0 && *src!= '\0')
	{
		*dst++ = *src++;
		len--;
	}
	// while (len > 0)
	// {
	// 	*d++ = '\0';
	// 	len--;
	// }
	return dst;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

