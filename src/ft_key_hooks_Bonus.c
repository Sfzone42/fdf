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

int	deal_key(int key, t_data *data)
{
	if (key == 65307)
	{
		free_map(data->map, data->height);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}	
	if (key == 'c')
	{
		if (data->current_color == 0)
			data->current_color = 1;
		else if (data->current_color == 1)
			data->current_color = 2;
		else if (data->current_color == 2)
			data->current_color = 0;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_map(data);
	}
	if (key == 'r')
		init_data(data);
	movimentar(key, data);
	zoom(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	usleep(0);
	return (0);
}

int	movimentar(int key, t_data *data)
{
	if (key == 65362)
		data->offset_y -= 50;
	else if (key == 65364)
		data->offset_y += 50;
	else if (key == 65361)
		data->offset_x -= 50;
	else if (key == 65363)
		data->offset_x += 50;
	else if (key == 'a')
		data->rotation_angle_y -= 5;
	else if (key == 'd')
		data->rotation_angle_y += 5;
	else if (key == 'w')
		data->rotation_angle_x -= 5;
	else if (key == 's')
		data->rotation_angle_x += 5;
	usleep(0);
	return (0);
}

int	zoom(int key, t_data *data)
{
	if (key == 61)
		data->scale += 1;
	else if (key == 45)
		data->scale -= 1;
	else if (key == 'p')
		data->z_scale += 1;
	else if (key == 'l')
		data->z_scale -= 1;
	usleep(0);
	return (0);
}

void	reset_format(t_data *data)
{
	int	required_width;
	int	required_height;

	required_width = data->width * data->scale;
	required_height = data->height * data->scale;
	if (required_width > LARGURA || required_height > ALTURA)
	{
		data->scale = 2;
		data->z_scale = 1;
		handle_error("Aviso: Dimensões ajustadas para caber na tela\n");
		required_width = data->width * data->scale;
		required_height = data->height * data->scale;
	}
	data->offset_x = (LARGURA / 2) - (required_width / 2);
	data->offset_y = (ALTURA / 2) - (required_height / 2);
}

void	init_data(t_data *data)
{
	data->scale = 10;
	data->z_scale = 1;
	reset_format(data);
	data->rotation_angle_x = 0;
	data->rotation_angle_y = 0;
	data->is_rotating = 0;
	data->current_color = 0;
}
