/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:23:47 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/18 12:25:01 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	color_control(t_infos *infos)
{
	t_infos	*tmp;
	char	**str;

	tmp = infos;
	while (tmp)
	{
		if (tmp->what == 6 || tmp->what == 7)
		{
			str = tmp->color;
			while (*str)
			{
				if (ft_atoi(*str) > 255 || ft_atoi(*str) < 0)
				{
					ft_printf("error\nthis value:%s is not ok\n", *str);
					return (0);
				}
				str++;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_info(char *str)
{
	while (*str == ' ')
		str++;
	if ((!ft_strncmp(str, "EA", 2) || !ft_strncmp(str, "NO", 2)
			|| !ft_strncmp(str, "SO", 2) || !ft_strncmp(str, "WE", 2))
		|| (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1)))
		return (1);
	return (0);
}

int	src_in_matrix(char **matrix, char *str)
{
	char	*point;

	while (*matrix)
	{
		point = *matrix;
		while (*point == ' ')
			str++;
		if (!ft_strncmp(point, str, ft_strlen(str)))
			return (1);
		matrix++;
	}
	return (0);
}

int	check_info2(char **info)
{
	if (src_in_matrix(info, "EA"))
		return (2);
	else if (src_in_matrix(info, "NO"))
		return (3);
	else if (src_in_matrix(info, "SO"))
		return (4);
	else if (src_in_matrix(info, "WE"))
		return (5);
	else if (src_in_matrix(info, "C"))
		return (6);
	else if (src_in_matrix(info, "F"))
		return (7);
	else
		return (1);
}

int	check_assets(t_data *data)
{
	int	fd;

	fd = open((find_in_list(data->info_list, 2))->str[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "bad texture path\n", 17), 1);
	close(fd);
	fd = open((find_in_list(data->info_list, 3))->str[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "bad texture path\n", 17), 1);
	close(fd);
	fd = open((find_in_list(data->info_list, 4))->str[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "bad texture path\n", 17), 1);
	close(fd);
	fd = open((find_in_list(data->info_list, 5))->str[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "bad texture path\n", 17), 1);
	close(fd);
	return (0);
}
