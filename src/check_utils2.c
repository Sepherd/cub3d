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
			if (s->f.map[x][y] != 10)
				s->f.tot++;
			y++;
			k++;
		}
		// ft_printf("%s", s->f.map[x]);
		i++;
		x++;
	}
	return (border_check(s));
}