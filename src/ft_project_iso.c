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

t_point	project_iso(t_point p, int scale, int z_scale)
{
	t_point	iso_point;

	iso_point.x = (p.x - p.y) * scale;
	iso_point.y = ((p.x + p.y) * scale) / 3 - p.z * z_scale;
	iso_point.z = p.z;
	return (iso_point);
}

int	ft_os_tres_idiotas(t_data *data)
{
	exit(0);
	free_map(data->map, data->height);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}
