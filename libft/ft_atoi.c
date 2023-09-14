/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:12:22 by arecce            #+#    #+#             */
/*   Updated: 2022/09/08 17:18:46 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(char *str)
{
	int			i;
	int			neg;
	long long	num;
	int			counter;

	i = 0;
	neg = 1;
	num = 0;
	counter = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while ((str[i] == '-' || str[i] == '+') && counter++ == 0)
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= neg;
	return (num);
}
