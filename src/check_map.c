# include "../cub3d.h"

//check degli angoli della mappa

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
			if (s->f.map[y][x] == 48)
				s->f.arr_map[i] = 0;
			else if (s->f.map[y][x] == 49)
				s->f.arr_map[i] = 1;
			else if (s->f.map[y][x] == 'N' || s->f.map[y][x] == 'S' \
				|| s->f.map[y][x] == 'E' || s->f.map[y][x] == 'W')
				s->f.arr_map[i] = 0;
			i++;
			x++;
		}
		y++;
	}
}

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
	s->pg.pdx = cos(degToRad(s->pg.pa));
	s->pg.pdy = -sin(degToRad(s->pg.pa));
	s->pg.pos_x = k * 64;
	s->pg.pos_y = i * 64;
}

int	map_line_check(t_scene *s)
{
	int		i;
	size_t	k;
	int		count;

	i = 1;
	count = 0;
	while (i < s->f.m_size - 2)
	{
		k = 1;
		while (k < ft_strlen(s->f.map[i]) - 2)
		{
			// ft_printf("%c", s->f.map[i][k]);
			if ((int)ft_strlen(s->f.map[i]) - 1 > s->f.map_x)
				s->f.map_x = ft_strlen(s->f.map[i]) - 1;
			if (s->f.map[i][k] == 48 || s->f.map[i][k] == 49)
			{
				// s->f.tot++;
				k++;
			}
			else if ((s->f.map[i][k] == 'N' || s->f.map[i][k] == 'S'
				|| s->f.map[i][k] == 'W' || s->f.map[i][k] == 'E') && count == 0)
			{	
				save_pg_position(s, s->f.map[i][k], i, k);
				count = 1;
				s->f.map[i][k] = '0';
				// s->f.tot++;
				k++;
			}
			else
				return (ft_perror("Mappa non valida"));
		}
		i++;
	}
	s->f.map_y = s->f.m_size;
	map_to_array(s);
	// s->screenX = s->f.map_x * 64;
	// s->screenY = s->f.map_y * 64;
	// ft_printf("TOT = %d\n", s->f.tot);
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
		if ((s->f.map[i][0] == 49 && s->f.map[i][ft_strlen(s->f.map[i]) - 2] == 49) \
			&& delta_walls(s, i))
			i++;
		else
			return (ft_perror("Mappa non chiusa nel modo corretto"));
	}
	k = 0;
	while (s->f.map[i][k])
	{
		if (s->f.map[i][k] != 32 && s->f.map[i][k] != 49 && s->f.map[i][k] != 10)
			return (ft_perror("Mappa non chiusa nel modo corretto"));
		k++;
	}
	return (map_line_check(s));
}