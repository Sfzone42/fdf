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

#include "fdf.h"

void	draw_line_with_offset(t_data *data,
t_point p1, t_point p2, t_points pts)
{
	p1.x += pts.offset.x;
	p1.y += pts.offset.y;
	p2.x += pts.offset.x;
	p2.y += pts.offset.y;
	draw_line(data, p1, p2, pts);
}

void	exo_x_with_offset(t_data *data, int x, int y, t_points pts)
{
	pts.p1 = (t_point){x * data->scale, y * data->scale, data->map[y][x]};
	pts.p2 = (t_point){(x + 1) * data->scale, y
		* data->scale, data->map[y][x + 1]};
	pts.iso_p1 = project_iso(pts.p1, 1, 1);
	pts.iso_p2 = project_iso(pts.p2, 1, 1);
	pts.color_p1 = map_height_to_color(
			pts.p1.z, data->limits.min_z, data->limits.max_z);
	pts.color_p2 = map_height_to_color(
			pts.p2.z, data->limits.min_z, data->limits.max_z);
	draw_line_with_offset(data, pts.iso_p1, pts.iso_p2, pts);
}

void	exo_y_with_offset(t_data *data, int x, int y, t_points pts)
{
	pts.p1 = (t_point){x * data->scale, y
		* data->scale, data->map[y][x]};
	pts.p2 = (t_point){x * data->scale, (y + 1)
		* data->scale, data->map[y + 1][x]};
	pts.iso_p1 = project_iso(pts.p1, 1, 1);
	pts.iso_p2 = project_iso(pts.p2, 1, 1);
	pts.color_p1 = map_height_to_color(
			pts.p1.z, data->limits.min_z, data->limits.max_z);
	pts.color_p2 = map_height_to_color(
			pts.p2.z, data->limits.min_z, data->limits.max_z);
	draw_line_with_offset(data, pts.iso_p1, pts.iso_p2, pts);
}

void	draw_iso_map(t_data *data)
{
	t_points	pts;
	int			x;
	int			y;

	adjust_scales(data, pts);
	calculate_iso_bounds(data, data->scale, &pts);
	pts.offset = calculate_offsets(pts);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				exo_x_with_offset(data, x, y, pts);
			if (y < data->height - 1)
				exo_y_with_offset(data, x, y, pts);
			x++;
		}
		y++;
	}
}
