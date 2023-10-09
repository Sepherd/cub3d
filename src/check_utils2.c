/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:43:25 by sepherd           #+#    #+#             */
/*   Updated: 2023/10/10 00:36:58 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	copy_map_utils(t_scene *s, int i)
{
	int	x;
	int	y;

	x = 0;
	while (i < s->f.f_size)
	{
		s->f.map[x] = ft_calloc(ft_strlen(s->f.file[i]) + 1, sizeof(char));
		y = 0;
		while (s->f.file[i][y])
		{
			if ((s->f.file[i][y] == 32 && (x == 0 || i == s->f.f_size - 1 \
				|| y == 0 || y == (int)ft_strlen(s->f.file[i] - 2))))
				s->f.map[x][y] = 49;
			else if (s->f.file[i][y] == 32)
				s->f.map[x][y] = 48;
			else
				s->f.map[x][y] = s->f.file[i][y];
			y++;
		}
		i++;
		x++;
	}
}

int	copy_map(t_scene *s, int i)
{
	s->f.m_size = s->f.f_size - i;
	s->f.map = malloc(sizeof(char **) * (s->f.m_size));
	if (s->f.m_size > 1)
		copy_map_utils(s, i);
	else
		return (ft_perror("Errore mappa"));
	return (border_check(s));
}

int	get_path_utils(t_scene *s, int i, int k)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_calloc(ft_strlen(s->f.file[i]) + 1, sizeof(char));
	while (s->f.file[i][k])
	{
		while (s->f.file[i][k] == 32)
			k++;
		while (s->f.file[i][k] != 32 && s->f.file[i][k] != '\n'
			&& s->f.file[i][k])
			tmp[j++] = s->f.file[i][k++];
		if (!check_id(s, tmp, i, k))
			return (0);
		free(tmp);
		break ;
	}
	return (1);
}

int	check_id(t_scene *s, char *tmp, int i, int k)
{
	if (ft_strcmp(tmp, NO_ID) && s->f.no_on == 0)
		return (get_texture_path(s, i, k, 0));
	else if (ft_strcmp(tmp, SO_ID) && s->f.so_on == 0)
		return (get_texture_path(s, i, k, 1));
	else if (ft_strcmp(tmp, EA_ID) && s->f.ea_on == 0)
		return (get_texture_path(s, i, k, 2));
	else if (ft_strcmp(tmp, WE_ID) && s->f.we_on == 0)
		return (get_texture_path(s, i, k, 3));
	else if (ft_strcmp(tmp, F_ID) && s->f.f_on == 0)
		return (get_texture_path(s, i, k, 4));
	else if (ft_strcmp(tmp, C_ID) && s->f.c_on == 0)
		return (get_texture_path(s, i, k, 5));
	return (ft_perror("ID non valido"));
}

void	convert_rgb(t_scene *s)
{
	s->f.f_color = ((uint32_t)s->f.f_r << 16) | ((uint32_t)s->f.f_g << 8) \
					| (uint32_t)s->f.f_b;
	s->f.c_color = ((uint32_t)s->f.c_r << 16) | ((uint32_t)s->f.c_g << 8) \
					| (uint32_t)s->f.c_b;
}
