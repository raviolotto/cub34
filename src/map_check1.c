/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacopo <jacopo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:21:57 by jcardina          #+#    #+#             */
/*   Updated: 2024/05/20 09:55:35 by jacopo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	map_height(t_data *map)
{
	int	height;

	height = 0;
	while (map->map[height])
		height++;
	return (height);
}

static int	check_around(char **m, size_t i, size_t j)
{
	while (iswhite(m[i][j]))
		j++;
	if (m[i][j] == '1')
		return (1);
	else if (m[i][j] != '1' && m[i][j] != '\n' && m[i][j] != '\0')
	{
		if (ft_strchr("01NSEW", m[i][j + 1]) == NULL)
			return (0);
		if (ft_strchr("01NSEW", m[i][j - 1]) == NULL)
			return (0);
		if (ft_strchr("01NSEW", m[i + 1][j]) == NULL)
			return (0);
		if (ft_strchr("01NSEW", m[i - 1][j]) == NULL)
			return (0);
	}
	return (1);
}

int	check_up_bottom(t_data *map, size_t i, size_t j)
{
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1'
			&& map->map[i][j] != ' ' && map->map[i][j] != 10)
			return (1);
		j++;
	}
	return (0);
}

int	check_map(t_data *map)
{
	size_t	i;
	size_t	j;
	size_t	height;

	i = -1;
	height = map_height(map) - 1;
	while (map->map[++i])
	{
		j = 0;
		if (i == 0 || i == height)
		{
			if (check_up_bottom(map, i, j))
				return (1);
		}
		else
		{
			while (j < ft_strlen(map->map[i]))
			{
				if (!check_around(map->map, i, j))
					return (1);
				j++;
			}
		}
	}
	return (0);
}

int	check_info3(char **info)
{
	if (src_in_matrix(info, "EA"))
		if (src_in_matrix(info, "NO"))
			if (src_in_matrix(info, "SO"))
				if (src_in_matrix(info, "WE"))
					if (src_in_matrix(info, "C"))
						if (src_in_matrix(info, "F"))
							return (1);
	return (0);
}
