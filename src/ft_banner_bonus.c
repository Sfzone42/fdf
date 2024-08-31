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

void	ft_banner_bonus(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 20, 0x6666ff, "INSTRUCOES:");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 40, 0xFFFFFF, "ESC: Sair");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 60, 0xFFFFFF, "C: Alterar cor");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 80, 0xFFFFFF, "R: Resetar");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 100, 0xFFFFFF, "Setas: Mover mapa");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 120, 0xFFFFFF, "A/D: Rotacionar eixo Y");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 140, 0xFFFFFF, "W/S: Rotacionar eixo X");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 160, 0xFFFFFF, "+/-: Zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 180, 0xFFFFFF, "P/L: Ajustar escala Z");
}
