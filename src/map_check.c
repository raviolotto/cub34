/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:22:02 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/27 17:49:12 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	catch_info(t_data *data, char **line)
{
	char	*infos;
	int		info_counter;

	info_counter = 0;
	infos = ft_strdup("");
	while (*line && info_counter < 6)
	{
		if (check_info(*line) == 1)
		{
			infos = super_strjoin(infos, *line);
			info_counter++;
		}
		free(*line);
		*line = get_next_line(data->fd);
	}
	data->info = ft_split(infos, '\n');
	free(infos);
	return (info_counter);
}

void	matrix_adderal(t_data *data, char *str)
{
	if(data->map == NULL)
	{
		data->map = ft_calloc(sizeof(char *), 2);
		data->map[0] = ft_strdup(str);
	}
	else
		data->map = matrix_newline(data->map, str);
}

void	catch_map(t_data *data, char **line)
{
	while (*line)
	{
		if(ft_strchr(*line, '1') != NULL)
			matrix_adderal(data, *line);
		free(*line);
		*line = get_next_line(data->fd);
	}
}

int	read_data(char *name, t_data *data)
{
	char	*line;

	data->fd = open(name, O_RDONLY);
	if (data->fd == -1)
		return (write(2, "Error\ninvalid file\n", 20), 1);
	line = get_next_line(data->fd);
	if (line == NULL)
		return (write(2, "Error\nempty file\n", 18), 1);
	if (catch_info(data, &line) != 6)
		return (write(2, "Error\nnot enouth info\n", 22), 1);
	catch_map(data, &line);
	print_matrix(data->map);
	if (check_map(data) == 1)
		return (write(2, "error\ninvalid map\n", 18), 1);
	if(check_info2(data->info) == 1)
		return (write(2, "Error\nnot enouth info\n", 22), 1);
	return (0);
}

int file_name(char *name)
{
	int len;

	len = ft_strlen(name);
	len = len - 4;
	if (ft_strncmp((name + len), ".cub", 4) != 0)
		return (1);
	return (0);
}

int	parser(int ac, char **av, t_data *data)
{

	if (ac != 2 || file_name(av[1]) == 1)
		return (write(1, "erro\n dumb input\n", 17), 1);
	if (read_data(av[1], data) == 1)
		return (1);
	if (lister(data) == 1)
		return (1);
	map_size(data);
	player_pos(data);
	return (0);
}
