/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:38:01 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 16:41:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	const char	*digit;
	int			len_print;

	digit = "0123456789";
	len_print = ft_numlen(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb == 0)
		ft_putchar('0');
	else
		ft_convert(nb, digit);
	return (len_print);
}
