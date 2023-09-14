/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:16:51 by arecce            #+#    #+#             */
/*   Updated: 2022/03/29 11:16:51 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	unsigned char	uc;

	uc = c;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (*s == uc)
		return ((char *)s);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * ((gnl_strlen(s1) + gnl_strlen(s2)) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
