/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:04:06 by arecce            #+#    #+#             */
/*   Updated: 2023/09/26 17:32:09 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_perror(char *msg)
{
	ft_printf("Error\n");
	ft_printf("\033[1;31m%s\033[1;0m\n", msg);
	exit(0);
	return (0);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	// char	*d;
	// char	*s;

	// *d = dst;
	// *s = src;
	while (len > 0 && *src!= '\0')
	{
		*dst++ = *src++;
		len--;
	}
	// while (len > 0)
	// {
	// 	*d++ = '\0';
	// 	len--;
	// }
	return dst;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	my_mlx_pixel_put(t_scene *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int hexStringToInt(char *hexString)
{
	int		result;
	char	currentChar;
	int		digitValue;

	digitValue = 0;
	result = 0;
	if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
		hexString += 2;
	while (*hexString)
	{
		currentChar = *hexString;
		if (currentChar >= '0' && currentChar <= '9')
			digitValue = currentChar - '0';
		else if (currentChar >= 'A' && currentChar <= 'F')
			digitValue = currentChar - 'A' + 10;
		else if (currentChar >= 'a' && currentChar <= 'f')
			digitValue = currentChar - 'a' + 10;
		else
			return (ft_perror("Carattere non valido nella stringa esadecimale"));
		result = result * 16 + digitValue;
		hexString++;
	}
	return (result);
}