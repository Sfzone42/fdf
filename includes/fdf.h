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

#ifndef FDF_H
# define FDF_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"

# define LARGURA 1360
# define ALTURA 720

typedef struct s_alg_pot
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_points
{
	t_point	iso_p1;
	t_point	p1;
	t_point	p2;
	t_point	iso_p2;
	t_point	offset;
	int		min_z;
	int		max_z;
	int		min_iso_x;
	int		max_iso_x;
	int		min_iso_y;
	int		max_iso_y;
	int		color_p1;
	int		color_p2;
}	t_points;

typedef struct s_alg_window
{
	t_points	limits;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			width;
	int			height;
	int			scale;
	int			z_scale;
}	t_data;

typedef struct s_alg_linw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line_params;

/*funções para criar matriz*/

void	fill_matrix(char **map, char *file_name, t_data *data);
void	check_line_width(int current_width, int width);
void	process_line(char **map, char *line, int i, t_data *data);
void	free_map(char **map, int height);
char	**allocate_map(int width, int height);
char	**read_map(char *file_name, t_data *data, int *min_z, int *max_z);
FILE	*open_file(char *file_name);
int		get_width(char *file_name);
int		count_words_in_line(char *line);
int		get_height(char *file_name);

/*funções para ler e desenhar o mapa na tela*/

void	exo_x_with_offset(t_data *data, int x, int y, t_points pts);
void	exo_y_with_offset(t_data *data, int x, int y, t_points pts);
void	draw_line(t_data *data, t_point p1, t_point p2, t_points pts);
void	draw_line_with_offset(t_data *data,
			t_point p1, t_point p2, t_points pts);
void	draw_iso_map(t_data *data);
void	draw_line_part(t_point *p1, t_line_params *params);
void	set_params(t_line_params *params, t_point p1, t_point p2);

/*funções para centralizar o mapa, 
aplicar a rotação e a perspectiva isometrica*/

t_point	calculate_offsets(t_points pts);
void	update_iso_bounds(t_point iso_p, t_points *pts);
void	calculate_iso_bounds(t_data *data,
			int scale, t_points *pts);
void	recalculate_iso_bounds(t_data *data, t_points *pts);
void	adjust_scale_down(t_data *data, t_points *pts);
void	adjust_scale_up(t_data *data, t_points *pts);
void	adjust_z_scale(t_data *data, t_points pts);
void	adjust_scales(t_data *data, t_points pts);

/*funções para manipular as cores*/

int		get_color(t_points pts, int steps, int i);
int		map_height_to_color(int height, int min_height, int max_height);

/*perspectiva isométrica*/

t_point	project_iso(t_point p, int scale, int z_scale);

/*funcoes auxiliares*/

void	handle_error(char *message);
int		max_int(int a, int b);
int		close_program(int key, void *param);
int		ft_check_est(char *s);
int		ft_os_tres_idiotas(t_data *data);

#endif
