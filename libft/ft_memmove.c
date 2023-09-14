/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:48:01 by arecce            #+#    #+#             */
/*   Updated: 2022/03/10 16:19:30 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	return (dst);
}
