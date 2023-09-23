/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:42:37 by arecce            #+#    #+#             */
/*   Updated: 2023/09/23 17:30:34 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	get_path(t_scene *s)
{
	char	*tmp;
	int		i;
	int		k;
	int		j;

	i = 0;
	while (i < s->f.f_size)
	{
		k = 0;
		if (!empty_line(s, i, k))
		{
			if (!map_start(s, i, k))
			{
				while (s->f.file[i][k])
				{
					while (s->f.file[i][k] == 32)
						k++;
					// if (s->f.file[i][k] == '\n')
					// 	break ;
					j = 0;
					tmp = ft_calloc(ft_strlen(s->f.file[i]) + 1, sizeof(char));
					while (s->f.file[i][k] != 32 && s->f.file[i][k] != '\n'
						&& s->f.file[i][k])
						tmp[j++] = s->f.file[i][k++];
					if (!check_id(s, tmp, i, k))
						return (0);
					free(tmp);
					break ;
					// if (s->f.file[i][k] == 32)
					// 	break ;
				}
			}
			else
				break ;
		}
		i++;
	}
	return (1);
}

int	copy_file(t_scene *s, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_perror("Impossibile aprire il file"));
	s->f.file = malloc(sizeof(char **) * s->f.f_size);
	i = 0;
	line = get_next_line(fd);
	s->f.file[i] = ft_calloc(ft_strlen(line) + 2, sizeof(char));
	// ft_printf("Linea: %d - Stringa: %s\n", i, line);
	ft_strncpy(s->f.file[i++], line, ft_strlen(line));
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		s->f.file[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		ft_strncpy(s->f.file[i], line, ft_strlen(line));
		i++;
	}
	close(fd);
	free(line);
	return (get_path(s));
}

int	open_file(t_scene *s, char *file)
{
	int		fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_perror("Impossibile aprire il file"));
	get_rows(s, fd);
	close(fd);
	return(copy_file(s, file));
}

int	check_file_type(t_scene *s, char *file, char *ext, int f)
{
	int		i;
	int		k;
	char	temp[5];

	i = ft_strlen(file) - 4;
	k = 0;
	while (file[i])
		temp[k++] = file[i++];
	temp[k] = '\0';
	if (!ft_strcmp(temp, ext))
	{
		if (f == 0)
			return (ft_perror("Il file non è nel formato .cub"));
		else if (f == 1)
			return (ft_perror("Il file non è nel formato .xpm"));
	}
	if (f == 0)
	{
		if (!open_file(s, file))
			return (0);
		s->f.f_color = ((uint32_t)s->f.f_r << 16) | ((uint32_t)s->f.f_g << 8) | (uint32_t)s->f.f_b;
		s->f.c_color = ((uint32_t)s->f.c_r << 16) | ((uint32_t)s->f.c_g << 8) | (uint32_t)s->f.c_b;
	}
	return (1);
}