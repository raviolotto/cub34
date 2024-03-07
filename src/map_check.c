/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:22:02 by jcardina          #+#    #+#             */
/*   Updated: 2024/03/07 16:39:49 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	read_data(char *name, t_data *data)
{
	char	*infos;
	char	*line;
	int		info_counter;

	info_counter = 0;
	data->fd = open(name, O_RDONLY);
	if(data->fd == -1)
		return(write(1, "Error\ninvalid file\n", 20), 1);
	line = get_next_line(data->fd);
	if(line == NULL)
		return (write(1, "Error\nempty file\n", 18), 1);
	infos = ft_strdup("");
	while(line && info_counter < 6)
	{
		if(check_info(line) == 1)
		{
			infos = super_strjoin(infos, line);
			info_counter++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	data->info = ft_split(infos, '\n');
	free(infos);
	//fare il controllo se i valori sono giusti;
	infos = ft_strdup("");
	while (line)
	{
		if(ft_strchr(line, '1') != NULL)
			infos = super_strjoin(infos, line);
		free(line);
		line = get_next_line(data->fd);
	}
	data->map = ft_split(infos, '\n');
	free(infos);
	if(check_map(data) == 1)
		return(write(2, "error\ninvalid map\n", 18), 1);
	print_matrix(data->map);
	print_matrix(data->info);
	return (0);
}

int file_name(char *name)
{
	int len;

	len = ft_strlen(name);
	len = len - 4;
	if(ft_strncmp((name + len), ".cub", 4) != 0)
		return(1);
	return(0);
}

int	parser(int ac, char **av, t_data *data)
{

	if(ac != 2 || file_name(av[1]) == 1)
		return(1);
	if(read_data(av[1], data) == 1)
		return (1);
	return(0);
}
