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

void	init_cores(t_color cores)
{
	cores.green = 0;
	cores.blue = 0;
	cores.red = 0;
}

int	map_height_to_color(int height, double min_height,
						double max_height, int current_color)
{
	double	normalized_height;
	t_color	cores;

	init_cores(cores);
	if (max_height == min_height)
		return (0xfff00f);
	normalized_height = (double)(height - min_height)
		/ (max_height - min_height);
	if (current_color == 0)
	{
		cores.red = (int)(normalized_height * 255);
		cores.green = (int)(normalized_height * 255);
		cores.blue = 255 - (int)(normalized_height * 255);
	}
	else if (current_color == 1)
	{
		cores.red = (int)(normalized_height * 255);
		cores.green = 255 - cores.red;
	}
	else if (current_color == 2)
	{
		cores.red = 255;
		cores.blue = 255 - cores.green;
	}
	return ((cores.red << 16) | (cores.green << 8) | cores.blue);
}

int	interpolate_color(int color_start, int color_end, float factor)
{
	t_colors	var_color;

	var_color.red_start = (color_start >> 16) & 0xFF;
	var_color.red_end = (color_end >> 16) & 0xFF;
	var_color.green_start = (color_start >> 8) & 0xFF;
	var_color.green_end = (color_end >> 8) & 0xFF;
	var_color.blue_start = color_start & 0xFF;
	var_color.blue_end = color_end & 0xFF;
	var_color.red = var_color.red_start + factor
		* (var_color.red_end - var_color.red_start);
	var_color.green = var_color.green_start + factor
		* (var_color.green_end - var_color.green_start);
	var_color.blue = var_color.blue_start + factor
		* (var_color.blue_end - var_color.blue_start);
	return ((var_color.red << 16) | (var_color.green << 8) | var_color.blue);
}
