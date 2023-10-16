/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:00 by arecce            #+#    #+#             */
/*   Updated: 2023/10/16 19:29:02 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	save_pg_position(t_scene *s, char direction, int i, int k)
{
	if (direction == 'N')
		s->pg.pa = 90;
	else if (direction == 'S')
		s->pg.pa = 270;
	else if (direction == 'E')
		s->pg.pa = 0;
	else if (direction == 'W')
		s->pg.pa = 180;
	s->pg.dasein = 1;
	s->pg.pdx = cos(deg_to_rad(s->pg.pa));
	s->pg.pdy = -sin(deg_to_rad(s->pg.pa));
	s->pg.pos_x = (k * 64) + 32;
	s->pg.pos_y = (i * 64) + 32;
	if (s->f.map_x <= s->f.m_size)
		s->r.dof_min = s->f.m_size;
	else
		s->r.dof_min = s->f.map_x;
}

void	map_to_array_check(t_scene *s, int y, int x, int i)
{
	if (s->f.map[y][x] == 48)
		s->f.arr_map[i] = 0;
	else if (s->f.map[y][x] == 49)
		s->f.arr_map[i] = 1;
	else if (s->f.map[y][x] == 'N' || s->f.map[y][x] == 'S' \
		|| s->f.map[y][x] == 'E' || s->f.map[y][x] == 'W')
		s->f.arr_map[i] = 0;
}

int	map_line_utils(t_scene *s, int i, int k)
{
	if ((int)ft_strlen(s->f.map[i]) - 1 > s->f.map_x)
		s->f.map_x = ft_strlen(s->f.map[i]) - 1;
	if (s->f.map[i][k] == 48 || s->f.map[i][k] == 49)
		k++;
	else if ((s->f.map[i][k] == 'N' || s->f.map[i][k] == 'S'
		|| s->f.map[i][k] == 'W' || s->f.map[i][k] == 'E'))
	{
		if (s->f.pg_count != 0)
			return (ft_perror("Errato numero di personaggi"));
		save_pg_position(s, s->f.map[i][k], i, k);
		s->f.pg_count = 1;
		s->f.map[i][k] = '0';
		k++;
	}
	else
		k = 0;
	return (k);
}

void	pair_the_map(t_scene *s)
{
	int		y;
	int		x;
	char	*tmp;

	y = 0;
	while (y < s->f.map_y)
	{
		if ((int)ft_strlen(s->f.map[y]) - 1 < s->f.map_x)
		{
			tmp = ft_calloc(ft_strlen(s->f.map[y]) + 1, sizeof(char));
			ft_strncpy(tmp, s->f.map[y], ft_strlen(s->f.map[y]));
			free(s->f.map[y]);
			s->f.map[y] = ft_calloc(s->f.map_x + 1, sizeof(char));
			x = -1;
			while (++x < (int)ft_strlen(tmp) - 1)
				s->f.map[y][x] = tmp[x];
			while (x < s->f.map_x)
				s->f.map[y][x++] = 49;
			free(tmp);
		}
		y++;
	}
}
