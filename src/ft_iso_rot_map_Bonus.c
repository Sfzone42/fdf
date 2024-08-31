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

void	calculate_offsets(t_data *data, t_point *offset)
{
	offset->x = data->offset_x;
	offset->y = data->offset_y;
}

void	rotate_x(int *y, int *z, int angle)
{
	double	radians;
	int		previous_y;
	int		previous_z;

	radians = angle * M_PI / 180;
	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(radians) - previous_z * sin(radians);
	*z = previous_y * sin(radians) + previous_z * cos(radians);
}

void	rotate_y(int *x, int *z, int angle)
{
	double	radians;
	int		previous_x;
	int		previous_z;

	radians = angle * M_PI / 180;
	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(radians) + previous_z * sin(radians);
	*z = -previous_x * sin(radians) + previous_z * cos(radians);
}

void	project_isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}
