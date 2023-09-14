/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:26 by arecce            #+#    #+#             */
/*   Updated: 2022/03/25 19:41:47 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = c;
	us = (unsigned char *) s;
	while (n > 0)
	{
		if (*us == uc)
			return (us);
		us++;
		n--;
	}
	return (0);
}
