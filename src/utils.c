/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:57:38 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 17:17:24 by arecce           ###   ########.fr       */
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
	while (len > 0 && *src != '\0')
	{
		*dst++ = *src++;
		len--;
	}
	return (dst);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	my_mlx_pixel_put(t_scene *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

int	hex_string_to_int(char *hex)
{
	int		result;
	char	curr_char;
	int		value;

	value = 0;
	result = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	while (*hex)
	{
		curr_char = *hex;
		if (curr_char >= '0' && curr_char <= '9')
			value = curr_char - '0';
		else if (curr_char >= 'A' && curr_char <= 'F')
			value = curr_char - 'A' + 10;
		else if (curr_char >= 'a' && curr_char <= 'f')
			value = curr_char - 'a' + 10;
		else
			return (ft_perror("Carattere non valido nella stringa hex"));
		result = result * 16 + value;
		hex++;
	}
	return (result);
}
