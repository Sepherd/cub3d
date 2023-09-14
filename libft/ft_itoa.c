/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:49:57 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 16:56:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= 10;
	return (count);
}

char	*ft_result(char *num, const char *digit, int len, int n)
{
	if (n == 0)
		num[--len] = '0';
	else
	{
		while (n > 0)
		{
		num[--len] = digit[n % 10];
		n /= 10;
		}
	}
	return (num);
}

char	*ft_itoa(int n)
{
	const char	*digit;
	char		*num;
	int			len;

	digit = "0123456789";
	len = ft_numlen(n);
	num = (char *)malloc(len + 1);
	if (!num)
		return (0);
	num[len] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		if (n == -2147483648)
		{
			num[1] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	return (ft_result(num, digit, len, n));
}
