/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhabacuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 04:29:15 by lhabacuc          #+#    #+#             */
/*   Updated: 2024/08/31 04:29:17 by lhabacuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_line_with_offset(t_data *data,
t_point p1, t_point p2, t_points pts)
{
	p1.x += pts.offset.x;
	p1.y += pts.offset.y;
	p2.x += pts.offset.x;
	p2.y += pts.offset.y;
	draw_line(data, p1, p2, pts);
}

void	draw_vertical_line(t_data *data, t_points *pts, int i, int j)
{
	pts->p2.x = j * data->scale;
	pts->p2.y = (i + 1) * data->scale;
	pts->p2.z = (int)data->map[i + 1][j] * data->z_scale;
	rotate_y(&pts->p2.x, &pts->p2.z, data->rotation_angle_y);
	rotate_x(&pts->p2.y, &pts->p2.z, data->rotation_angle_x);
	pts->iso_p2.x = pts->p2.x;
	pts->iso_p2.y = pts->p2.y;
	project_isometric(&pts->iso_p2.x, &pts->iso_p2.y, pts->p2.z);
	pts->color_p2 = map_height_to_color(pts->p2.z,
			data->limits.min_z, data->limits.max_z, data->current_color);
	draw_line_with_offset(data, pts->iso_p1, pts->iso_p2, *pts);
}

void	draw_horizontal_line(t_data *data, t_points *pts, int i, int j)
{
	pts->p2.x = (j + 1) * data->scale;
	pts->p2.y = i * data->scale;
	pts->p2.z = (int)data->map[i][j + 1] * data->z_scale;
	rotate_y(&pts->p2.x, &pts->p2.z, data->rotation_angle_y);
	rotate_x(&pts->p2.y, &pts->p2.z, data->rotation_angle_x);
	pts->iso_p2.x = pts->p2.x;
	pts->iso_p2.y = pts->p2.y;
	project_isometric(&pts->iso_p2.x, &pts->iso_p2.y, pts->p2.z);
	pts->color_p2 = map_height_to_color(pts->p2.z,
			data->limits.min_z, data->limits.max_z, data->current_color);
	draw_line_with_offset(data, pts->iso_p1, pts->iso_p2, *pts);
}

void	process_point(t_data *data, t_points *pts, int i, int j)
{
	pts->p1.x = j * data->scale;
	pts->p1.y = i * data->scale;
	pts->p1.z = (int)data->map[i][j] * data->z_scale;
	rotate_y(&pts->p1.x, &pts->p1.z, data->rotation_angle_y);
	rotate_x(&pts->p1.y, &pts->p1.z, data->rotation_angle_x);
	pts->iso_p1.x = pts->p1.x;
	pts->iso_p1.y = pts->p1.y;
	project_isometric(&pts->iso_p1.x, &pts->iso_p1.y, pts->p1.z);
	pts->color_p1 = map_height_to_color(pts->p1.z,
			data->limits.min_z, data->limits.max_z, data->current_color);
	if (j < data->width - 1)
		draw_horizontal_line(data, pts, i, j);
	if (i < data->height - 1)
		draw_vertical_line(data, pts, i, j);
}

void	draw_map(t_data *data)
{
	t_points	pts;
	int			i;
	int			j;

	calculate_offsets(data, &pts.offset);
	data->img = mlx_new_image(data->mlx_ptr, LARGURA, ALTURA);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			process_point(data, &pts, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 10, 20);
	ft_banner_bonus(data);
	mlx_destroy_image(data->mlx_ptr, data->img);
}
