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

void	recalculate_iso_bounds(t_data *data, t_points *pts)
{
	calculate_iso_bounds(data, data->scale, pts);
}

void	adjust_scale_down(t_data *data, t_points *pts)
{
	int	map_width_iso;
	int	map_height_iso;

	recalculate_iso_bounds(data, pts);
	map_width_iso = pts->max_iso_x - pts->min_iso_x;
	map_height_iso = pts->max_iso_y - pts->min_iso_y;
	while (map_width_iso > LARGURA || map_height_iso > ALTURA)
	{
		data->scale--;
		recalculate_iso_bounds(data, pts);
		map_width_iso = pts->max_iso_x - pts->min_iso_x;
		map_height_iso = pts->max_iso_y - pts->min_iso_y;
	}
}

void	adjust_scale_up(t_data *data, t_points *pts)
{
	int	map_width_iso;
	int	map_height_iso;

	recalculate_iso_bounds(data, pts);
	map_width_iso = pts->max_iso_x - pts->min_iso_x;
	map_height_iso = pts->max_iso_y - pts->min_iso_y;
	while (map_width_iso < LARGURA / 2 && map_height_iso < ALTURA / 2)
	{
		data->scale++;
		recalculate_iso_bounds(data, pts);
		map_width_iso = pts->max_iso_x - pts->min_iso_x;
		map_height_iso = pts->max_iso_y - pts->min_iso_y;
	}
}

void	adjust_z_scale(t_data *data, t_points pts)
{
	int	z_range;

	z_range = pts.max_z - pts.min_z;
	if (z_range > 0)
	{
		data->z_scale = max_int(1, ALTURA / (z_range * 3));
	}
}

void	adjust_scales(t_data *data, t_points pts)
{
	data->scale = 1;
	data->z_scale = 1;
	adjust_scale_down(data, &pts);
	adjust_scale_up(data, &pts);
	adjust_z_scale(data, pts);
}
