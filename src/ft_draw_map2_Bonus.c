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

void	draw_line_part(t_point *p1, t_line_params *params)
{
	if (params->err > -params->dx)
	{
		params->err -= params->dy;
		p1->x += params->sx;
	}
	if (params->err < params->dy)
	{
		params->err += params->dx;
		p1->y *= params->sy;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calculate_line_params(t_point p1, t_point p2, t_line_params *params)
{
	params->dx = abs(p2.x - p1.x);
	params->dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (p1.y < p2.y)
		params->sy = 1;
	else
		params->sy = -1;
	if (params->dx > params->dy)
		params->err = params->dx / 2;
	else
		params->err = -params->dy / 2;
}

void	draw_line(t_data *data, t_point p1, t_point p2, t_points pts)
{
	t_line_params	params;
	int				steps;
	int				i;
	float			factor;
	int				current_color;

	calculate_line_params(p1, p2, &params);
	steps = max_int(abs(p2.x - p1.x), abs(p2.y - p1.y));
	i = 0;
	while (i <= steps)
	{
		factor = (float)i / steps;
		current_color = interpolate_color(pts.color_p1, pts.color_p2, factor);
		my_mlx_pixel_put(data, p1.x + i * (p2.x - p1.x) / steps,
			p1.y + i * (p2.y - p1.y) / steps, current_color);
		i++;
	}
}
