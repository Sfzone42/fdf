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

int	ft_os_tres_idiotas(t_data *data)
{
	exit(0);
	free_map(data->map, data->height);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	ft_check_est(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
		{
			j = 0;
			while (".fdf"[j] != '\0' && ".fdf"[j] == s[i])
			{
				i++;
				j++;
			}
		}
		i++;
	}
	if (j == 4)
		return (0);
	handle_error("error... Extensão inválida!\n");
	return (-1);
}

void	handle_error(char *message)
{
	perror(message);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		handle_error("Erro: Número de argumentos inválido!");
		return (EXIT_FAILURE);
	}
	if (ft_check_est(argv[1]) == -1)
		return (-1);
	data.map = read_map(argv[1], &data, &data.limits.min_z, &data.limits.max_z);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		handle_error("Erro: A inicialização da biblioteca mlx falhou!");
	data.win_ptr = mlx_new_window(data.mlx_ptr, LARGURA, ALTURA, "FDF___3wy");
	if (!data.win_ptr)
		handle_error("Erro: Criação da janela falhou!");
	init_data(&data);
	draw_map(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_os_tres_idiotas, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
