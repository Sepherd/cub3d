# include "../cub3d.h"

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
		if (s->f.file[i][k] != 32 && s->f.file[i][k] != 49 && s->f.file[i][k] != 10)
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
			return (save_texture_path(s, tmp, id));	
		}
	}
	return (save_texture_color(s, i, k, id));
}

int	check_id(t_scene *s, char *tmp, int i, int k)
{
	if (ft_strcmp(tmp, NO_ID) && s->f.no_on == 0)
		return (get_texture_path(s, i, k, 0));
	else if (ft_strcmp(tmp, SO_ID)  && s->f.so_on == 0)
		return (get_texture_path(s, i, k, 1));
	else if (ft_strcmp(tmp, EA_ID)  && s->f.ea_on == 0)
		return (get_texture_path(s, i, k, 2));
	else if (ft_strcmp(tmp, WE_ID)  && s->f.we_on == 0)
		return (get_texture_path(s, i, k, 3));
	else if (ft_strcmp(tmp, F_ID)  && s->f.f_on == 0)
		return (get_texture_path(s, i, k, 4));
	else if (ft_strcmp(tmp, C_ID)  && s->f.c_on == 0)
		return (get_texture_path(s, i, k, 5));
	return (ft_perror("ID non valido"));
}