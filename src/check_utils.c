/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:16 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 16:56:18 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	id_on(t_scene *s)
{
	if (s->f.no_on == 1 && s->f.so_on == 1 && s->f.ea_on == 1
		&& s->f.we_on == 1 && s->f.f_on == 1 && s->f.c_on == 1)
		return (1);
	return (0);
}

int	map_start(t_scene *s, int i, int k)
{
	while (s->f.file[i][k])
	{
		if (s->f.file[i][k] != 32 && s->f.file[i][k] != 49 \
			&& s->f.file[i][k] != 10)
			return (0);
		k++;
	}
	if (!id_on(s))
		return (ft_perror("Id non completi"));
	return (copy_map(s, i));
}

int	empty_line(t_scene *s, int i, int k)
{
	if (s->f.file[i][k] == 10)
		return (1);
	else
	{
		while (s->f.file[i][k])
		{
			if (s->f.file[i][k] != 32 && s->f.file[i][k] != '\n')
				return (0);
			k++;
		}
	}
	return (1);
}

void	get_rows(t_scene *s, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		s->f.f_size++;
	}
	free(line);
}

int	count_word(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) && line[i] != 32)
		{
			while (line[i] != 32 && line[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}
