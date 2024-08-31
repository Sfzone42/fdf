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

void	update_iso_bounds(t_point iso_p, t_points *pts)
{
	if (iso_p.x < pts->min_iso_x)
		pts->min_iso_x = iso_p.x;
	if (iso_p.x > pts->max_iso_x)
		pts->max_iso_x = iso_p.x;
	if (iso_p.y < pts->min_iso_y)
		pts->min_iso_y = iso_p.y;
	if (iso_p.y > pts->max_iso_y)
		pts->max_iso_y = iso_p.y;
}

void	calculate_iso_bounds(t_data *data, int scale, t_points *pts)
{
	t_point	p;
	t_point	iso_p;
	int		x;
	int		y;

	pts->min_iso_x = INT_MAX;
	pts->max_iso_x = INT_MIN;
	pts->min_iso_y = INT_MAX;
	pts->max_iso_y = INT_MIN;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			p = (t_point){x * scale, y * scale, data->map[y][x]};
			iso_p = project_iso(p, 1, 1);
			update_iso_bounds(iso_p, pts);
			x++;
		}
		y++;
	}
}

t_point	calculate_offsets(t_points pts)
{
	pts.offset.x = (LARGURA - (pts.max_iso_x - pts.min_iso_x))
		/ 2 - pts.min_iso_x;
	pts.offset.y = (ALTURA - (pts.max_iso_y - pts.min_iso_y))
		/ 2 - pts.min_iso_y;
	return (pts.offset);
}
