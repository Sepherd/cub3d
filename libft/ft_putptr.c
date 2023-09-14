/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:13:41 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 16:41:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptrconvert(uintptr_t ptr, char *digit)
{
	if (ptr > 0)
	{
		ft_ptrconvert(ptr / 16, digit);
		ft_putchar(digit[ptr % 16]);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int		len_print;
	char	*digit;

	digit = "0123456789abcdef";
	len_print = 0;
	len_print += (ft_putstr("0x") + ft_ptr_len(ptr));
	if (ptr == 0)
		len_print += ft_putchar('0');
	else
		ft_ptrconvert(ptr, digit);
	return (len_print);
}
