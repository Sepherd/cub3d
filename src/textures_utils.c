/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:57:33 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 16:57:35 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	save_texture_path(t_scene *s, char *tmp, int id)
{
	if (!check_file_type(s, tmp, ".xpm", 1))
		return (0);
	if (id == 0 && open(tmp, O_RDONLY) > 0)
	{
		save_textures(s, id, tmp);
		s->f.no_on = 1;
	}
	else if (id == 1 && open(tmp, O_RDONLY) > 0)
	{
		save_textures(s, id, tmp);
		s->f.so_on = 1;
	}
	else if (id == 2 && open(tmp, O_RDONLY) > 0)
	{
		save_textures(s, id, tmp);
		s->f.ea_on = 1;
	}
	else if (id == 3 && open(tmp, O_RDONLY) > 0)
	{
		save_textures(s, id, tmp);
		s->f.we_on = 1;
	}
	else
		return (ft_perror("Percorso texture non valido"));
	return (1);
}

void	save_value(t_scene *s, int num, int count, int id)
{
	if (count == 0)
	{
		if (id == 4)
			s->f.f_r = num;
		else if (id == 5)
			s->f.c_r = num;
	}
	else if (count == 1)
	{
		if (id == 4)
			s->f.f_g = num;
		else if (id == 5)
			s->f.c_g = num;
	}
	else if (count == 2)
	{
		if (id == 4)
			s->f.f_b = num;
		else if (id == 5)
			s->f.c_b = num;
	}
}

int	save_texture_color(t_scene *s, int i, int k, int id)
{
	int	num;
	int	count;

	count = 0;
	while (s->f.file[i][k] != 10 && s->f.file[i][k])
	{
		num = 0;
		while (s->f.file[i][k] == 32)
			k++;
		while ((s->f.file[i][k] >= '0') && (s->f.file[i][k] <= '9'))
			num = num * 10 + (s->f.file[i][k++] - '0');
		save_value(s, num, count, id);
		while (s->f.file[i][k] == 32)
			k++;
		while (s->f.file[i][k] == ',')
			k++;
		if ((num < 0 || num > 255) || (++count > 3))
			return (ft_perror("Valore RGB non corretto"));
	}
	if (id == 4)
		s->f.f_on = 1;
	else if (id == 5)
		s->f.c_on = 1;
	return (1);
}

int	get_texture_path(t_scene *s, int i, int k, int id)
{
	char	*tmp;
	int		j;

	if (id < 4)
	{
		j = 0;
		while (s->f.file[i][k] || s->f.file[i][k] != '\n')
		{
			while (s->f.file[i][k] == 32)
				k++;
			tmp = ft_calloc(ft_strlen(s->f.file[i]) + 1, sizeof(char));
			while (s->f.file[i][k] != 32 && ft_isprint(s->f.file[i][k]))
				tmp[j++] = s->f.file[i][k++];
			while (s->f.file[i][k] != '\n')
			{
				if (s->f.file[i][k] != 32)
					return (ft_perror("Path non valido"));
				k++;
			}
			j = save_texture_path(s, tmp, id);
			free(tmp);
			return (j);
		}
	}
	return (save_texture_color(s, i, k, id));
}
