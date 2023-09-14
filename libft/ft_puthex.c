/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:48:09 by arecce            #+#    #+#             */
/*   Updated: 2023/05/20 12:54:07 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int nb, const char c)
{
	int			len_print;

	len_print = ft_hex_len(nb);
	// if (nb < 0)
	// 	return (0);
	if (nb == 0)
		len_print += ft_putchar('0');
	else
	{
		ft_hexconvert(nb, c);
	}
	return (len_print);
}
