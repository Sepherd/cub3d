/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:09 by arecce            #+#    #+#             */
/*   Updated: 2023/10/16 19:10:54 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_to_array(t_scene *s)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	s->f.tot = s->f.map_y * s->f.map_x;
	s->f.arr_map = malloc(sizeof(int) * s->f.tot);
	while (y < s->f.map_y)
	{
		x = 0;
		while (x < s->f.map_x)
		{
			map_to_array_check(s, y, x, i);
			i++;
			x++;
		}
		y++;
	}
}

int	map_line_check(t_scene *s)
{
	int		i;
	size_t	k;

	i = 1;
	while (i < s->f.m_size - 1)
	{
		k = 1;
		while (k < ft_strlen(s->f.map[i]) - 2)
		{
			if (k != 0)
				k = map_line_utils(s, i, k);
			else
				return (ft_perror("Mappa non valida"));
		}
		i++;
	}
	s->f.map_y = s->f.m_size;
	pair_the_map(s);
	map_to_array(s);
	if (!s->pg.dasein)
		return (ft_perror("Personaggio non presente"));
	return (1);
}

int	delta_walls(t_scene *s, int i)
{
	int	d;
	int	k;

	d = ft_strlen(s->f.map[i]) - ft_strlen(s->f.map[i + 1]);
	if (d > 0)
	{
		k = ft_strlen(s->f.map[i]) - 2;
		while (d-- > 0)
		{
			if (s->f.map[i][k] != 49)
				return (0);
			k--;
		}
	}
	else if (d < 0)
	{
		k = ft_strlen(s->f.map[i + 1]) - 2;
		while (d++ < 0)
		{
			if (s->f.map[i + 1][k] != 49)
				return (0);
			k--;
		}
	}
	return (1);
}

int	border_check(t_scene *s)
{
	int	i;
	int	k;

	i = 1;
	while (i < s->f.m_size - 1)
	{
		if ((s->f.map[i][0] == 49 && \
			s->f.map[i][ft_strlen(s->f.map[i]) - 2] == 49) && delta_walls(s, i))
			i++;
		else
			return (ft_perror("Mappa non chiusa nel modo corretto"));
	}
	k = 0;
	while (s->f.map[i][k])
	{
		if (s->f.map[i][k] != 32 && s->f.map[i][k] != 49 \
			&& s->f.map[i][k] != 10)
			return (ft_perror("Mappa non chiusa nel modo corretto"));
		k++;
	}
	return (map_line_check(s));
}
