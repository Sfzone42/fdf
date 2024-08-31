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

int	map_height_to_color(int height, int min_height, int max_height)
{
	int	color_intensity;

	if (max_height == min_height)
		return (0xfff00f);
	color_intensity = 255 * (height - min_height) / (max_height - min_height);
	return ((0 << 16) | (color_intensity << 8) | (255 - color_intensity));
}

int	get_color(t_points pts, int steps, int i)
{
	int	color_step_r;
	int	color_step_g;
	int	color_step_b;

	color_step_r = ((pts.color_p2 >> 16) & 0xFF)
		- ((pts.color_p1 >> 16) & 0xFF);
	color_step_g = ((pts.color_p2 >> 8) & 0xFF) - ((pts.color_p1 >> 8) & 0xFF);
	color_step_b = (pts.color_p2 & 0xFF) - (pts.color_p1 & 0xFF);
	return (((((pts.color_p1 >> 16) & 0xFF) + color_step_r * i / steps) << 16)
		| ((((pts.color_p1 >> 8) & 0xFF) + color_step_g * i / steps) << 8)
		|(((pts.color_p1 & 0xFF) + color_step_b * i / steps)));
}
