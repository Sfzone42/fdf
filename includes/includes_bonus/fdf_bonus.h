/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 04:29:15 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/31 04:29:17 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"

# define LARGURA 1920
# define ALTURA 1080

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}	t_point;

typedef struct s_limits
{
	double	min_z;
	double	max_z;
}	t_limits;

typedef struct s_data
{
	t_limits	limits;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		**map;
	char		*addr;
	int			width;
	int			height;
	int			scale;
	int			z_scale;
	int			offset_x;
	int			offset_y;
	int			rotation_angle_x;
	int			rotation_angle_y;
	int			is_rotating;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			current_color;
}	t_data;

typedef struct s_line_params
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}	t_line_params;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_points
{
	t_point	iso_p1;
	t_point	p1;
	t_point	p2;
	t_point	iso_p2;
	t_point	offset;
	int		color_p1;
	int		color_p2;
}	t_points;
typedef struct s_cores
{
	int	red_start;
	int	red_end;
	int	green_start;
	int	green_end;
	int	blue_start;
	int	blue_end;
	int	red;
	int	green;
	int	blue;
}	t_colors;

/*funcao para mandar uma mensagem*/

void	ft_banner_bonus(t_data *data);
void	handle_error(char *message);
int		ft_check_est(char *s);
int		ft_os_tres_idiotas(t_data *data);

/*funções para centralizar o mapa, 
aplicar a rotação e a perspectiva isometrica*/

void	calculate_offsets(t_data *data, t_point *offset);
void	rotate_x(int *y, int *z, int angle);
void	rotate_y(int *x, int *z, int angle);
void	project_isometric(int *x, int *y, int z);

/*funções para criar matriz*/

void	check_line_width(int current_width, int width);
void	free_map(char **map, int height);
void	process_line(char **map, char *line, int i, t_data *data);
void	fill_matrix(char **map, char *file_name, t_data *data);
char	**allocate_map(int width, int height);
FILE	*open_file(char *file_name);
int		count_words_in_line(char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);

/*funções para leitura de teclas(movimentação, zoom, reset etc..)*/

int		movimentar(int key, t_data *data);
int		zoom(int key, t_data *data);
int		deal_key(int key, t_data *data);
void	reset_format(t_data *data);
void	init_data(t_data *data);

/*funções para manipular as cores*/

void	init_cores(t_color cores);
int		interpolate_color(int color_start, int color_end, float factor);
int		max_int(int a, int b);
int		map_height_to_color(int height, double min_height,
			double max_height, int current_color);

/*funções para ler e desenhar o mapa na tela*/

void	draw_horizontal_line(t_data *data, t_points *pts, int i, int j);
void	draw_vertical_line(t_data *data, t_points *pts, int i, int j);
void	process_point(t_data *data, t_points *pts, int i, int j);
void	draw_map(t_data *data);
void	draw_line_part(t_point *p1, t_line_params *params);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	calculate_line_params(t_point p1, t_point p2, t_line_params *params);
void	draw_line(t_data *data, t_point p1, t_point p2, t_points pts);
void	draw_line_with_offset(t_data *data,
			t_point p1, t_point p2, t_points pts);
char	**read_map(char *file_name, t_data *data, double *min_z, double *max_z);

#endif
