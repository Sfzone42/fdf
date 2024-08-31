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

int	count_words_in_line(char *line)
{
	int	i;
	int	current_width;

	current_width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
			current_width++;
		i++;
	}
	return (current_width);
}

void	check_line_width(int current_width, int width)
{
	if (current_width != width)
		handle_error("Erro: o mapa tem coluna a mais em uma das linhas!");
}

FILE	*open_file(char *file_name)
{
	FILE	*file;

	file = fopen(file_name, "r");
	if (!file)
		handle_error("Erro: Não conseguimos abrir o arquivo!");
	return (file);
}

int	get_width(char *file_name)
{
	FILE	*file;
	char	*line;
	size_t	len;
	ssize_t	read;
	int		width;

	file = open_file(file_name);
	line = NULL;
	len = 0;
	read = getline(&line, &len, file);
	if (read == -1)
		handle_error("Erro: Não conseguimos abrir o arquivo!");
	width = count_words_in_line(line);
	read = getline(&line, &len, file);
	while (read != -1)
	{
		check_line_width(count_words_in_line(line), width);
		read = getline(&line, &len, file);
	}
	free(line);
	fclose(file);
	return (width);
}

int	get_height(char *file_name)
{
	FILE	*file;
	char	*line;
	size_t	len;
	ssize_t	read;
	int		height;

	file = fopen(file_name, "r");
	if (!file)
		handle_error("Erro: Não conseguimos abrir o arquivo");
	line = NULL;
	len = 0;
	height = 0;
	read = getline(&line, &len, file);
	while (read != -1)
	{
		height++;
		read = getline(&line, &len, file);
	}
	free(line);
	fclose(file);
	return (height);
}
