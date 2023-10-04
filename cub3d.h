/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:42:48 by arecce            #+#    #+#             */
/*   Updated: 2023/10/04 11:27:27 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
// # include "keymap/key_linux.h"
// # include "mlx_linux/mlx.h"

# if defined(__APPLE__)
#  include "keymap/key_mac.h"
#  include "mlx/mlx.h"
# else
#  include "keymap/key_linux.h"
#  include "mlx_linux/mlx.h"
# endif

# define PI 3.1415926535
// # define P2 PI/2
// # define P3 3*PI/2
// # define DR	0.0174533

# define NO_ID "NO"
// # define NO_PATH "./img/no_wall.xpm"
# define SO_ID "SO"
// # define SO_PATH "./img/so_wall.xpm"
# define EA_ID "EA"
// # define EA_PATH "./img/ea_wall.xpm"
# define WE_ID "WE"
// # define WE_PATH "./img/we_wall.xpm"
# define F_ID "F"
# define C_ID "C"
# define TEX_X 64
# define TEX_Y 64
# define SCREEN_X 640
# define SCREEN_Y 640

typedef struct s_textures
{
	char	***temp_color;
	char	***temp_pixel;
	int		tot_col;
	int		*no_tex;
	int		*so_tex;
	int		*ea_tex;
	int		*we_tex;
	int		index;
	int		color;
}				t_textures;

typedef struct s_ray
{
	int		rr;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		dof_min;
	double	rx;
	double	ry;
	double	ra;
	double	r_tan;
	double	xo;
	double	yo;
	double	dis_h;
	double	hx;
	double	hy;
	double	dis_v;
	double	vx;
	double	vy;
	double	shade;
	char	wall_side;
}				t_ray;

typedef struct s_file
{
	int			no_on;
	int			so_on;
	int			we_on;
	int			ea_on;
	int			f_on;
	int			f_r;
	int			f_g;
	int			f_b;
	uint32_t	f_color;
	int			c_on;
	int			c_r;
	int			c_g;
	int			c_b;
	uint32_t	c_color;
	char		**file;
	int			f_size;
	char		*map_start;
	int			map_on;
	char		**map;
	int			tot;
	int			m_size;
	int			count;
	int			map_x;
	int			map_y;
	int			*arr_map;
}				t_file;

typedef struct s_pg
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	pdx;
	double	pdy;
	double	pa;
	int		press_s;
	int		press_a;
	int		press_d;
	int		press_w;
	int		press_la;
	int		press_ra;
	int		xo;
	int		yo;
	int		ipx;
	int		ipy;
	int		ipx_add_xo;
	int		ipx_sub_xo;
	int		ipy_add_yo;
	int		ipy_sub_yo;
}				t_pg;

typedef struct s_scene
{
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits;
	int			line_len;
	int			endian;
	void		*no_wall;
	void		*so_wall;
	void		*ea_wall;
	void		*we_wall;
	t_textures	t;
	t_pg		pg;
	t_file		f;
	t_ray		r;
}				t_scene;

/***** INIT *****/
void	init_ray(t_scene *s);
void	init(t_scene *s);

/***** UTILS *****/
int		ft_perror(char *msg);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		empty_line(t_scene *s, int i, int k);
int		hex_string_to_int(char *hex);
void	my_mlx_pixel_put(t_scene *data, int x, int y, int color);
int		exit_game(t_scene *s);
void	mov_utils(t_scene *s);
int		get_path_utils(t_scene *s, int i, int k);
int		is_position_valid(t_scene *s, double x, double y);
int		mov(t_scene *s);
int		key(int keycode, t_scene *s);
int		keyup(int keycode, t_scene *s);
void	movement(int keycode, t_scene *s);
void	convert_rgb(t_scene *s);
void	pair_the_map(t_scene *s);

/***** CHECK *****/
void	map_to_array_check(t_scene *s, int y, int x, int i);
int		map_line_utils(t_scene *s, int i, int k);
void	get_rows(t_scene *s, int fd);
int		count_word(char *line);
int		copy_file(t_scene *s, char *file);
int		get_id(t_scene *s);
int		check_id(t_scene *s, char *tmp, int i, int k);
int		check_file_type(t_scene *s, char *file, char *ext, int f);
int		map_start(t_scene *s, int i, int k);
int		copy_map(t_scene *s, int i);
int		border_check(t_scene *s);

/***** TEXTURES *****/
void	free_matrix(char ***matrix, int x, int y);
int		get_texture_path(t_scene *s, int i, int k, int id);
int		array_alloc(t_scene *s, int id);
void	save_pixels(t_scene *s, char *tmp, int i, int id);
void	save_char_color(t_scene *s, char *tmp, int i, int id);
void	save_tex_utils(t_scene *s, int fd, int id);
int		save_textures(t_scene *s, int id, char *file);

/***** DRAW *****/
void	my_mlx_pixel_put(t_scene *data, int x, int y, int color);
void	draw_floor_ceiling(t_scene *s, int y1, int y2, int color);
void	draw_walls(t_scene *s, int y, int line_h, double ty_off);
// void	draw_square(t_scene *s, int x, int y, int lt, int color);
// void	drawMap(t_scene *s);
// void	draw_line(t_scene *s, int len);
// void drawCircle(t_scene *s, int centerX, int centerY, int radius, int color);
// void	drawLine(t_scene *s, int x, int y, int color);
// void	drawLine(t_scene *s, int x0, int y0, int x1, int y1);
// void	 drawLine(t_scene *s, int x1, int y1, int angle);
// void	drawLine(t_scene *s, int ex, int ey, int color);

	/***** RAY *****/
double	deg_to_rad(double a);
double	fix_ang(double a);
void	ray(t_scene *s);
double	deg_to_rad(double a);
double	fix_ang(double a);
void	ray_vertical_dof(t_scene *s);
void	ray_horizontal_dof(t_scene *s);

#endif