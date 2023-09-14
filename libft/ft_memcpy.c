/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:25:11 by arecce            #+#    #+#             */
/*   Updated: 2022/03/11 11:16:35 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char		*udst;
	unsigned const char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
		*udst++ = *usrc++;
	return (dst);
}
