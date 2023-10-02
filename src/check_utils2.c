/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:43:25 by sepherd           #+#    #+#             */
/*   Updated: 2023/10/03 00:48:13 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_size(t_scene *s)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s->f.file[i] != NULL && !ft_strcmp(s->f.file[i], s->f.map_start))
		i++;
	if (ft_strcmp(s->f.file[i], s->f.map_start))
	{
		while (s->f.file[i] != NULL)
		{
			i++;
			size++;
		}
	}
	ft_printf("MAP SIZE = %d\n", size);
	return (size);
}

int	copy_map(t_scene *s, int i)
{
	int	k;
	int	x;
	int	y;

	s->f.m_size = s->f.f_size - i;
	s->f.map = malloc(sizeof(char **) * (s->f.m_size));
	x = 0;
	while (i < s->f.f_size)
	{
		k = 0;
		y = 0;
		s->f.map[x] = ft_calloc(ft_strlen(s->f.file[i]) + 1, sizeof(char));
		while (s->f.file[i][k])
		{
			if (s->f.file[i][k] == 32)
				s->f.map[x][y] = 49;
			else
				s->f.map[x][y] = s->f.file[i][k];
			y++;
			k++;
		}
		i++;
		x++;
	}
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
