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

void	process_line(char **map, char *line, int i, t_data *data)
{
	int		j;
	int		z;
	char	*num;

	j = 0;
	num = strtok(line, " \n");
	while (num)
	{
		z = ft_atoi(num);
		map[i][j] = (char)z;
		if (z < data->limits.min_z)
			data->limits.min_z = z;
		if (z > data->limits.max_z)
			data->limits.max_z = z;
		num = strtok(NULL, " \n");
		j++;
	}
}

void	fill_matrix(char **map, char *file_name, t_data *data)
{
	FILE	*file;
	char	*line;
	size_t	len;
	ssize_t	read;
	int		i;

	line = NULL;
	len = 0;
	i = 0;
	file = fopen(file_name, "r");
	if (!file)
		handle_error("Erro: Não conseguimos abrir o arquivo");
	data->limits.min_z = INT_MAX;
	data->limits.max_z = INT_MIN;
	read = getline(&line, &len, file);
	while (read != -1)
	{
		process_line(map, line, i, data);
		i++;
		read = getline(&line, &len, file);
	}
	free(line);
	fclose(file);
}

char	**allocate_map(int width, int height)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * height);
	if (!map)
		handle_error("Erro: alocação de memória falhou!");
	i = 0;
	while (i < height)
	{
		map[i] = (char *)malloc(sizeof(char) * width);
		if (!map[i])
			handle_error("Erro: alocação de memória falhou!");
		i++;
	}
	return (map);
}

char	**read_map(char *file_name, t_data *data, int *min_z, int *max_z)
{
	char	**map;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->width <= 0 || data->height <= 0)
		handle_error("Dimensões inválidas");
	map = allocate_map(data->width, data->height);
	fill_matrix(map, file_name, data);
	return (map);
}
