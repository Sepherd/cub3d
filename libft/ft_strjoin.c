/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:41:36 by arecce            #+#    #+#             */
/*   Updated: 2022/03/15 14:27:32 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = (s1_len + s2_len);
	str = (char *) malloc(total_len + 1);
	if (!str)
		return (0);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
